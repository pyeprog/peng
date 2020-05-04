#include <iostream>
#include <vector>
#include <pmp/SurfaceMesh.h>
#include <boost/geometry.hpp>
#include <boost/geometry/geometries/point.hpp>
#include <boost/geometry/geometries/box.hpp>
#include <boost/version.hpp>


using namespace pmp;
namespace bg = boost::geometry;

int main(int argc, char** argv) {
    // instantiate a SurfaceMesh object
    SurfaceMesh mesh;

    // instantiate 4 vertex handles
    Vertex v0, v1, v2, v3, v4, v5, v6, v7, v8;

    // add 4 vertices
    v0 = mesh.add_vertex(Point(0, 0, 0));
    v1 = mesh.add_vertex(Point(1, 0, 0));
    v2 = mesh.add_vertex(Point(2, 0, 0));
    v3 = mesh.add_vertex(Point(0, 1, 0));
    v4 = mesh.add_vertex(Point(1.2, 1.5, 0));
    v5 = mesh.add_vertex(Point(2, 1, 0));
    v6 = mesh.add_vertex(Point(0, 2, 0));
    v7 = mesh.add_vertex(Point(1, 2, 0));
    v8 = mesh.add_vertex(Point(2, 2, 0));

    // add 4 triangular faces
    mesh.add_quad(v0, v1, v4, v3);
    mesh.add_quad(v1, v2, v5, v4);
    mesh.add_quad(v3, v4, v7, v6);
    mesh.add_quad(v4, v5, v8, v7);

    if (argc > 1) {
        mesh.write(argv[1]);
    }
    std::cout << "done" << std::endl;

    typedef bg::model::point<float, 2, bg::cs::cartesian> point;

    typedef bg::model::point<float, 2, bg::cs::cartesian> point;
    typedef bg::model::box<point> box;
    typedef bg::model::polygon<point, false, false> polygon; // ccw, open polygon
    typedef std::pair<box, unsigned> value;

    // polygons
    std::vector<polygon> polygons;

    // create some polygons
    for ( unsigned i = 0 ; i < 10 ; ++i )
    {
        // create a polygon
        polygon p;
        for ( float a = 0 ; a < 6.28316f ; a += 1.04720f )
        {
            float x = i + int(10*::cos(a))*0.1f;
            float y = i + int(10*::sin(a))*0.1f;
            p.outer().push_back(point(x, y));
        }

        // add polygon
        polygons.push_back(p);
    }

    std::cout << "Polygon has " << polygons.size() << std::endl;
    std::cout << "Using Boost " << BOOST_VERSION / 100000 << "."
              << BOOST_VERSION / 100 % 1000 << "."
              << BOOST_VERSION % 100 << std::endl;

    return 0;
}