#include <stdio.h>
#include <math.h>

double update_joint(double angle, double voltage)
{
    double deg_per_tick = 45.0;
    if (angle >= 90.0 || angle <= -90.0) return angle;

    return angle + (deg_per_tick*voltage);
}
    
int main()
{

    // constants
    const double tau1 = 0.5;       // u1,u2 time constant larger means longer cycle
    const double tau2 = 1.2;        // v1,v2 time ...
    const double beta = 100.0;        // weight between ui, vi. if beta<1 attenuate; beta>1 causes interesting patterns 
    const double omega = 1.5;      // weight between flexor, extensor neuron pairs 
    const double ue = 1.0;          // external input
    const double u1_init = 0.1;     // neuron intial states
    const double v1_init = 10.0;     // ...
    const double u2_init = 1.0;
    const double v2_init = 0.1;
    const double motor = 1;

    //const double euler_step = 0.03125;
    //const double euler_step = 0.0625;
    const double euler_step = 0.125;
    //const double euler_step = 1.0;

    // neuron states
    double u1 = u1_init;
    double v1 = v1_init;
    double u2 = u2_init;
    double v2 = v2_init;

    // neuron derivatives
    double u1d = 0.0;
    double v1d = 0.0;
    double u2d = 0.0;
    double v2d = 0.0;

    double y1 = 0.0;                // max(0, ui)
    double y2 = 0.0;

    double angle = 0.0;
    //const double feedback_coef = 1.0;
    const double feedback_coef = 1/90.0;
    double voltage = 0.0;
    double f1 = 0.0;
    double f2 = 0.0;

    for (int i=0; i<1E2; i++)
    {
        //printf("i=%d\nu1=%lf v1=%lf u1d=%lf v1d=%lf\nu2=%lf v2=%lf u2d=%lf v2d=%lf\n",
                //i, u1, v1, u1d, v1d, u2, v2, u1d, v1d);
        //printf("y1=%lf y2=%lf\n", y1, y2);

        y1 = fmax(0.0, u1);
        y2 = fmax(0.0, u2);

        //if (angle > 0) f1 = feedback_coef * (angle - 90);
        //if (angle < 0) f1 = feedback_coef * (angle + 90);
        //f1 = feedback_coef * angle;
        //f2 = -f1;


        u1d = (-u1 - omega*y2 - beta*v1 + ue + f1) / tau1;
        v1d = (-v1 + y1) / tau2;
        u2d = (-u2 - omega*y1 - beta*v2 + ue + f2) / tau1;
        v2d = (-v2 + y2) / tau2;

        u1 += u1d*euler_step;
        v1 += v1d*euler_step;
        u2 += u2d*euler_step;
        v2 += v2d*euler_step;

        voltage = -motor*y1+motor*y2;
        //angle = update_joint(angle, voltage);

        //printf("%d\t%lf\n", i, angle);
        printf("%d\t%lf\n", i, voltage);

    }

    return 0;
}

