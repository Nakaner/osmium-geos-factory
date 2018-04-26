#include <osmium_geos_factory/geos_factory.hpp>

#include "catch.hpp"

#include <osmium/geom/mercator_projection.hpp>


TEST_CASE("GEOS geometry factory with MercatorProjection") {
    osmium_geos_factory::GEOSFactory<osmium::geom::MercatorProjection> factory;

    const std::unique_ptr<geos::geom::Point> point{factory.create_point(osmium::Location{3.2, 4.2})};
    REQUIRE(Approx(356222.3705384755l) == point->getX());
    REQUIRE(Approx(467961.143605213l) == point->getY());
    REQUIRE(3857 == point->getSRID());
}
