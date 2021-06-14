PROJECT : 104 INTERSECTION

DESCRIPTION :

    To create synthesis images (when doing ray tracing, for example), potential intersection points between light rays and scene objects (here cylinders, spheres and cones) must be computed. This is exactly whatyou have to do in this project.

    To do so, you need to write a 3 dimensional equation of the considered surface, and inject into it the equa-tion of the straight line representing the light ray.

    You’ll get a quadratic equation, with 0, 1, 2 or an infinitenumber of solutions that will give you the intersection points coordinates.

    The straight line is defined by the coordinates of a point by which it passes through and the coordinates of a parallel vector.

    O being the origin of the coordinate system, and X, Y and Z the axis, the surfaces that must be handledin this project are:

    • O-centered spheres,

    • Cylinders of revolution around Z axis,

    • Cones of revolution around Z axis whose apex is O.


USAGE :

    ./104intersection opt xp yp zp xv yv zv p

COMMANDE :

    opt             surface option: 1 for the sphere, 2 for the cylinder, 3 for the cone

    (xp, yp, zp)    coordinates of a point by which the light ray passes through

    (xv, yv, zv)    coordinates of a vector parallel to the light ray

    p               parameters: radius of the sphere, radius of the cylinder, or
                    angle formed by the cone and the Z-axis