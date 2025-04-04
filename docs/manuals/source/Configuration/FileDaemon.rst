.. _FiledConfChapter:

Client/File Daemon Configuration
================================

:index:`\ <single: Configuration; Client/File daemon>`\  :index:`\ <single: Client/File daemon Configuration>`\

The Client (or File Daemon) Configuration is one of the simpler ones to specify. Generally, other than changing the Client name so that error messages are easily identified, you will not need to modify the default Client configuration file.

For a general discussion of configuration file and resources including the data types recognized by Bareos, please see the :ref:`Configuration <ConfigureChapter>` chapter of this manual. The following Client Resource definitions must be defined:

-  :ref:`Client <ClientResourceClient>` – to define what Clients are to be backed up.

-  :ref:`Director <ClientResourceDirector>` – to define the Director’s name and its access password.

-  :ref:`Messages <MessagesChapter>` – to define where error and information messages are to be sent.

.. _ClientResourceClient:

Client Resource
---------------

:index:`\ <single: Resource; Client>`\  :index:`\ <single: Client Resource>`\

The Client (or File Daemon) resource defines the name of the Client (as used by the Director) as well as the port on which the Client listens for Director connections.

Start of the Client records. There must be one and only one Client resource in the configuration file, since it defines the properties of the current client program.

.. include:: /include/autogenerated/bareos-fd-resource-client-table.rst.inc

.. include:: /include/autogenerated/bareos-fd-resource-client-description.rst.inc

The following is an example of a valid Client resource definition:



::

   Client {                              # this is me
     Name = rufus-fd
   }



.. _ClientResourceDirector:

Director Resource
-----------------

:index:`\ <single: Director Resource>`\  :index:`\ <single: Resource; Director>`\

The Director resource defines the name and password of the Directors that are permitted to contact this Client.

.. include:: /include/autogenerated/bareos-fd-resource-director-table.rst.inc

.. include:: /include/autogenerated/bareos-fd-resource-director-description.rst.inc

Thus multiple Directors may be authorized to use this Client’s services. Each Director will have a different name, and normally a different password as well.

The following is an example of a valid Director resource definition:



::

   #
   # List Directors who are permitted to contact the File daemon
   #
   Director {
     Name = HeadMan
     Password = very_good                # password HeadMan must supply
   }
   Director {
     Name = Worker
     Password = not_as_good
     Monitor = Yes
   }



.. _ClientResourceMessages:

Messages Resource
-----------------

.. index::
   single: Messages Resource
   single: Resource; Messages

There must be at least one Message resource in the Client configuration file.

Please see the :ref:`Messages Resource <MessagesChapter>` Chapter of this manual for the details of the Messages Resource.

.. include:: /include/autogenerated/bareos-fd-resource-messages-table.rst.inc

.. include:: /include/autogenerated/bareos-fd-resource-messages-description.rst.inc


Example File Daemon Configuration File
--------------------------------------

An example File Daemon configuration file might be the following:



::

   #
   # Bareos File Daemon Configuration file
   #

   #
   # List Directors who are permitted to contact this File daemon
   #
   Director {
     Name = bareos-dir
     Password = "aEODFz89JgUbWpuG6hP4OTuAoMvfM1PaJwO+ShXGqXsP"
   }

   #
   # Restricted Director, used by tray-monitor to get the
   #   status of the file daemon
   #
   Director {
     Name = client1-mon
     Password = "8BoVwTju2TQlafdHFExRIJmUcHUMoIyIqPJjbvcSO61P"
     Monitor = yes
   }

   #
   # "Global" File Daemon configuration specifications
   #
   Client {                          # this is me
     Name = client1-fd
     Maximum Concurrent Jobs = 20

     # remove comment in next line to load plugins from specified directory
     # Plugin Directory = /usr/lib64/bareos/plugins
   }

   # Send all messages except skipped files back to Director
   Messages {
     Name = Standard
     director = client1-dir = all, !skipped, !restored
   }
