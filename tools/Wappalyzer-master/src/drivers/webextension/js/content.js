(function() {
	var c = {
		init: function() {
			var html = document.documentElement.outerHTML;

			c.log('init');

			if ( html.length > 50000 ) {
				html = html.substring(0, 25000) + html.substring(html.length - 25000, html.length);
			}

			browser.runtime.sendMessage({ id: 'analyze', subject: { html: html } });

			c.getEnvironmentVars();
		},

		log: function(message) {
			browser.runtime.sendMessage({ id: 'log', message: '[ content.js ] ' + message });
		},

		getEnvironmentVars: function() {
			var container, script;

			c.log('getEnvironmentVars');

			if ( typeof document.documentElement.innerHTML === 'undefined' ) {
				return;
			}

			try {
				container = document.createElement('wappalyzerData');

				container.setAttribute('id',    'wappalyzerData');
				container.setAttribute('style', 'display: none');

				script = document.createElement('script');

				script.setAttribute('id', 'wappalyzerEnvDetection');
				script.setAttribute('src', browser.extension.getURL('js/inject.js'));

				container.addEventListener('wappalyzerEvent', (function(event) {
					var environmentVars = event.target.childNodes[0].nodeValue;

					document.documentElement.removeChild(container);
					document.documentElement.removeChild(script);

					environmentVars = environmentVars.split(' ').slice(0, 500);

					browser.runtime.sendMessage({ id: 'analyze', subject: { env: environmentVars } });
				}), true);

				document.documentElement.appendChild(container);
				document.documentElement.appendChild(script);
			} catch(e) {
				c.log('Error: ' + e);
			}
		}
	}

	c.init();
}());
