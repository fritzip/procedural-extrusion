#include <iterator>
#include <eigen3/Eigen/Dense>

#include "house.h"
 
using namespace std;
using namespace Eigen;


// void print_co(XYZco co)
// {
// 	printf("x = %.3f, y = %.3f, z = %.3f\n", co.x, co.y, co.z);
// }


// XYZco wz_to_xyz(const WZco &p1, const WZco &p2, double y)
// {
// 	return XYZco({p2.z*tan(PI*p1.w/180)*180/PI, y, p2.z});
// }


int intersect_is_point( const Plane &p1, const Plane &p2, const Plane &p3 )
{
	MatrixXd m(3,3);
	MatrixXd maug(3,4);
	m << p1[0], p1[1], p1[2], p2[0], p2[1], p2[2], p3[0], p3[1], p3[2];
	maug << p1[0], p1[1], p1[2], p1[3], p2[0], p2[1], p2[2], p2[3], p3[0], p3[1], p3[2], p3[3];
	FullPivLU<MatrixXd> lum(m);
	FullPivLU<MatrixXd> lumaug(maug);
	return (lum.rank() == 3 && lumaug.rank() == 3);
}


Vector intersect_3_planes( const Plane &p1, const Plane &p2, const Plane &p3 )
{
	// return ((dot(p1.get_vert()[0],  p1.get_norm())*(p2.get_norm()*p3.get_norm()))
	// 	+   (dot(p2.get_vert()[0],  p2.get_norm())*(p.get_norm()*p3.get_norm()))
	// 	+   (dot(p3.get_vert()[0],  p3.get_norm())*(p2.get_norm()*p3.get_norm())))
	// 	/ (det3(p1.get_norm(), p2.get_norm(), p3.get_norm()));
	return Vector();
}

//  x=(|n_1^^ n_2^^ n_3^^|)^(-1)[(x_1·n_1^^)(n_2^^xn_3^^)+(x_2·n_2^^)(n_3^^xn_1^^)+(x_3·n_3^^)(n_1^^xn_2^^)], 	
// (8)

// where |n_1^^ n_2^^ n_3^^| is the determinant of the matrix formed by writing the vectors n_i^^ side-by-side. If two of the planes are parallel, then
// |n_1^^ n_2^^ n_3^^|=0, 



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


