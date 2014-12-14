#include <iterator>
#include <eigen3/Eigen/Dense>

#include "cdll.h"
 
using namespace std;
using namespace Eigen;

void print_co(XYZco co)
{
	printf("x = %.3f, y = %.3f, z = %.3f\n", co.x, co.y, co.z);
}


XYZco wz_to_xyz(const WZco &p1, const WZco &p2, double y)
{
	return XYZco({p2.z*tan(PI*p1.w/180)*180/PI, y, p2.z});
}

int intersect_is_point( const Plane &p1, const Plane &p2, const Plane &p3 )
{
	MatrixXd m(3,3);
	MatrixXd maug(3,4);
	m << p1.get_a(), p1.get_b(), p1.get_c(), p2.get_a(), p2.get_b(), p2.get_c(), p3.get_a(), p3.get_b(), p3.get_c();
	maug << p1.get_a(), p1.get_b(), p1.get_c(), p1.get_d(), p2.get_a(), p2.get_b(), p2.get_c(), p2.get_d(), p3.get_a(), p3.get_b(), p3.get_c(), p3.get_d();
	FullPivLU<MatrixXd> lum(m);
	FullPivLU<MatrixXd> lumaug(maug);
	return (lum.rank() == 3 && lumaug.rank() == 3);
}


XYZco intersect_3_planes( const Plane &p1, const Plane &p2, const Plane &p3 )
{
	//
	return XYZco();
}


void Plane::compute_plan( const XYZco &p, const XYZco &q, const XYZco &r  )
{
	this->a = ( q.y - p.y ) * ( r.z - p.z ) - ( q.z - p.z ) * ( r.y - p.y );
	this->b = ( q.z - p.z ) * ( r.x - p.x ) - ( q.x - p.x ) * ( r.z - p.z );
	this->c = ( q.x - p.x ) * ( r.y - p.y ) - ( q.y - p.y ) * ( r.x - p.x );
	this->d = - ( this->a * p.x + this->b * p.y + this->c * p.z );
}


void House::extrude()
{
	PriorityQ Q();
	Plan active_plan(level.back());
	Plane p1, p2, p3;
	// for (list<Corndge>::iterator itc=active_plan.ce.begin(); itc != active_plan.ce.end(); ++itc)
	// {
	// 	for (list<Corndge>::iterator ite=active_plan.ce.begin(); ite != active_plan.ce.end(); ++ite)
	// 	{
	// 		p1 = (*ite).get_edge().get_dir_plane();
	// 		p2 = (*itc).get_edge().get_dir_plane();
	// 		if (itc == active_plan.ce.begin())
	// 			p3 = active_plan.ce.back().get_edge().get_dir_plane();
	// 		else
	// 			p3 = (*next(itc)).get_edge().get_dir_plane();

	for (Plan::iterator itc=active_plan.begin(); itc != active_plan.end(); ++itc)
	{
		for (Plan::iterator ite=active_plan.begin(); ite != active_plan.end(); ++ite)
		{
			p1 = (*ite).get_dir_plane();
			p2 = (*itc).get_dir_plane();
			if (itc == active_plan.begin())
				p3 = active_plan.back().get_dir_plane();
			else
				p3 = (*next(itc)).get_dir_plane();


			if (!(&p1 == &p2 || &p1 == &p3 || &p2 == &p3) && intersect_is_point(p1, p2, p3))
			{
				print_co(intersect_3_planes(p1, p2, p3));
			}
			// event = ;

			// Q.push(event);
		}	
	}
}


