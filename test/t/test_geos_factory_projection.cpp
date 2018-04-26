#include <osmium_geos_factory/geos_factory.hpp>

#include "catch.hpp"

#include <osmium/geom/projection.hpp>


TEST_CASE("GEOS geometry factory with MercatorProjection") {
    osmium_geos_factory::GEOSFactory<osmium::geom::Projection> factory {osmium::geom::Projection(31467)};

    const std::unique_ptr<geos::geom::Point> point{factory.create_point(osmium::Location{8.9434922214, 49.0984980009})};
    REQUIRE(Approx(3495948.74709) == point->getX());
    REQUIRE(Approx(5440143.11381) == point->getY());
    REQUIRE(31467 == point->getSRID());
}
