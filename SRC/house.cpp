#include <iterator>

#include "house.h"
 
using namespace std;


// void print_co(XYZco co)
// {
// 	printf("x = %.3f, y = %.3f, z = %.3f\n", co.x, co.y, co.z);
// }


// XYZco wz_to_xyz(const WZco &p1, const WZco &p2, double y)
// {
// 	return XYZco({p2.z*tan(PI*p1.w/180)*180/PI, y, p2.z});
// }



void House::extrude()
{
	PriorityQ Q();
	Plan active_plan(level.back());
	Plane p1, p2, p3;

	// for (Plan::iterator itc=active_plan.begin(); itc != active_plan.end(); ++itc)
	// {
	// 	for (Plan::iterator ite=active_plan.begin(); ite != active_plan.end(); ++ite)
	// 	{
	// 		p1 = (*ite).get_dir_plane();
	// 		p2 = (*itc).get_dir_plane();
	// 		if (itc == active_plan.begin())
	// 			p3 = active_plan.back().get_dir_plane();
	// 		else
	// 			p3 = (*next(itc)).get_dir_plane();


	// 		if (!(&p1 == &p2 || &p1 == &p3 || &p2 == &p3) && intersect_is_point(p1, p2, p3))
	// 		{
	// 			print_co(intersect_3_planes(p1, p2, p3));
	// 		}
	// 		// event = ;

	// 		// Q.push(event);
	// 	}	
	// }
}


