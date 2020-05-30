#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cmath>
#include "spline.h"
#include "coordinate_transforms.h"

template<class Function>
double deriv1(const Function& f, double x)
{
	double dx=1e-8*(1.0+fabs(x));
	double x0=x-dx;
	double x2=x+dx;
	return (f(x2)-f(x0)) / (2.0*dx);
}

template<class Function>
double deriv2(const Function& f, double x)
{
	double dx=1e-6*(1.0+fabs(x));
	double x0=x-dx;
	double x2=x+dx;
	return (f(x0)-2.0*f(x)+f(x2)) / (dx*dx);
}


int main(int argc, char** argv) {

	if(argc<1) {
		printf("usage: %s <>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
    
	std::vector<double> X(6), Y(6);
	X[0]=0.0; X[1]=2; X[2]= 4.0; X[3]=6.0; X[4]=8.0; X[5]=10;
	Y[0]=0.0; Y[1]=1; Y[2]=-0.5; Y[3]=0.5; Y[4]=-0.3; Y[5]=0.0;

	tk::spline s;
    s.set_boundary(tk::spline::second_deriv, 0.0,
                   tk::spline::first_deriv, -2.0, false);
    s.set_points(X,Y);

    for(size_t i=0; i<X.size(); i++) {
        printf("%f %f\n", X[i], Y[i]);
    }
    printf("\n");
    int num_points = 200;
    std::vector<double> maps_x(num_points), maps_y(num_points);
    for(int i=0; i<=num_points; i++) {
        double x=0.05*i;
        maps_x[i] = x;
        maps_y[i] = s(x);
        printf("%f %f %f %f %f\n", maps_x[i], maps_y[i],
               s.deriv(1,x), s.deriv(2,x), s.deriv(3,x));
        // checking analytic derivatives and finite differences are close
        assert(fabs(s.deriv(1,x)-deriv1(s,x)) < 1e-8);
        assert(fabs(s.deriv(2,x)-deriv2(s,x)) < 1e-8);
    }
    printf("\n");
    std::vector<double> x_test(4);
    std::vector<double> y_test(4);
	x_test[0]=0.0; x_test[1]=4;    x_test[2]= 3.0; x_test[3]=8; 
	y_test[0]=0.0; y_test[1]=-0.5; y_test[2]= 1.0; y_test[3]=-1; 
    for(int i=0; i<4; i++){
		printf("%f %f %f %f\n", x_test[i], y_test[i], getFrenet(x_test[i], y_test[i], maps_x, maps_y)[0], getFrenet(x_test[i], y_test[i], maps_x, maps_y)[1]);	
	}
    return EXIT_SUCCESS;
}
