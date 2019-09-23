.. sslyze documentation master file, created by
   sphinx-quickstart on Sun Jan 15 12:41:02 2017.
   You can adapt this file completely to your liking, but it should at least
   contain the root `toctree` directive.

Step 1: Testing Connectivity to a Server
****************************************

.. module:: sslyze.server_connectivity

Basic Example
=============

Before a server can be scanned, SSLyze must ensure that it is able to reach the server. This is achieved using the
`ServerConnectivityInfo` class::

    try:
        server_info = ServerConnectivityInfo(hostname=u'www.google.com')
        server_info.test_connectivity_to_server()
    except ServerConnectivityError as e:
        # Could not establish an SSL connection to the server
        raise RuntimeError(u'Error when connecting to {}: {}'.format(hostname, e.error_msg))

If the call to `test_connectivity_to_server()` returns successfully, the `server_info` is then ready to be used for
scanning the server. This is described in :doc:`running-scan-commands`.

Advanced Usage
==============

The ServerConnectivityInfo classs provides fine-grained controls regarding how SSLyze should connect to a server. If
only a hostname is supplied (like in the example above), default values will be used and SSLyze will assume that the
server is an HTTPS server listening on port 443.

Several additional settings can be supplied in order to be more specific about the protocol the SSL/TLS server uses
(such as StartTLS) and how to connect to it (for example by supplying an IP address or a client certificate).

The ServerConnectivityInfo class
--------------------------------

.. autoclass:: ServerConnectivityInfo()
   :members: __init__, test_connectivity_to_server


Enabling StartTLS and other supported protocols
-----------------------------------------------

.. module:: sslyze.ssl_settings
.. autoclass:: TlsWrappedProtocolEnum
   :undoc-members:
   :members:

Running scan commands through a proxy
-------------------------------------

.. autoclass:: HttpConnectTunnelingSettings()
   :members: __init__, from_url

Enabling client authentication
------------------------------

.. autoclass:: ClientAuthenticationCredentials()
   :members: __init__

.. module:: nassl.ssl_client
.. autoclass:: OpenSslFileTypeEnum
   :undoc-members:
   :members:




