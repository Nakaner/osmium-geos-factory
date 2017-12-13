# Osmium GEOS Factory

Osmium GEOS Factory is a plugin for the [Osmium library version
2.x](http://osmcode.org/libosmium) (also known as Libosmium).

Osmium contained a factory for GEOS geometry objects originally but it was
removed because it used the GEOS C++ API which [is not considered to be
stable](https://lists.osgeo.org/pipermail/geos-devel/2017-January/007653.html).
This repository contains the factory and all modifications to make it work with
both GEOS 3.5 and GEOS 3.6.

## License

Osmium GEOS Factory is available under the Boost Software License. See
[LICENSE.txt](LICENSE.txt).

## Authors

The GEOSFactoryImpl class of Libosmium was written by Jochen Topf
(jochen@topf.org). Adaption to GEOS 3.6 was added by Michael Reichert
(michael.reichert@geofabrik.de).  See the git commit log for other authors.

