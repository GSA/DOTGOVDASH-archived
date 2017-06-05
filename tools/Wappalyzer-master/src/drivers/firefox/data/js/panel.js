(function() {
	self.port.on('displayApps', function(message) {
		var
			div, a, img, label, name, slugify, confidence, version,
			d = document,
			detectedApps = d.getElementById('detected-apps'),
			empty = d.getElementById('empty');

		slugify = function(string) {
			return string.toLowerCase().replace(/[^a-z0-9-]/g, '-').replace(/--+/g, '-').replace(/(?:^-|-$)/g, '');
		};

		while ( detectedApps.firstChild ) {
			detectedApps.removeChild(detectedApps.firstChild);
		}

		if ( message.tabs.count > 0 ) {
			empty.style.display = 'none';

			for ( appName in message.tabs.appsDetected ) {
				div   = d.createElement('div');
				a     = d.createElement('a');
				img   = d.createElement('img');
				label = d.createElement('span');
				name  = d.createElement('span');

				confidence = message.tabs.appsDetected[appName].confidenceTotal;
				version    = message.tabs.appsDetected[appName].version;

				div.setAttribute('class', 'detected-app');

				a.setAttribute('href', '#');

				(function(appName) {
					a.addEventListener('click', function(e) {
						e.preventDefault();

						self.port.emit('goToUrl', 'applications/' + slugify(appName));
					});
				}(appName));

				img.setAttribute('src',    'images/icons/' + message.apps[appName].icon);
				img.setAttribute('height', '16');
				img.setAttribute('width',  '16');

				label.setAttribute('class', 'label');

				name.setAttribute('class', 'name');

				name.appendChild(d.createTextNode(appName));

				label.appendChild(name);
				label.appendChild(d.createTextNode(( version ? ' ' + version : '' ) + ( confidence < 100 ? ' (' + confidence + '% sure)' : '')));

				a.appendChild(img);
				a.appendChild(label);

				div.appendChild(a);

				message.apps[appName].cats.forEach(function(cat) {
					a     = d.createElement('a');
					label = d.createElement('span');
					name  = d.createElement('span');

					a.setAttribute('href', '#');

					(function(appName) {
						a.addEventListener('click', function(e) {
							e.preventDefault();

							self.port.emit('goToUrl', 'categories/' + slugify(message.categories[cat]));
						});
					}(appName));

					label.setAttribute('class', 'category');

					name.setAttribute('class', 'name');

					name.appendChild(d.createTextNode(message.categoryNames[cat]));

					label.appendChild(name);

					a.appendChild(label);

					div.appendChild(a);
				});

				detectedApps.appendChild(div);
			}
		} else {
			empty.style.display = 'inherit';
		}

		self.port.emit('resize', document.body.offsetHeight);
	});
}());
