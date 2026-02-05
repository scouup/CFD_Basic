# Stage 2：One-Dimensional advective wave equation_Acoustic

## 1. Governing equation
This is a simplified equation for perturbed convective wave equation. I hope that I can know more physics about this simple equation.

The governing equation is: 
\[
\frac{D^2\psi}{Dt^2} - c_0^2 \frac{D^2\psi}{Dx^2} = 0 
\]

The material derivative is 
\[
    \frac{D}{Dt} = \frac{\partial}{\partial t} + U \frac{\partial}{\partial x}
\]

Here 
- $c_0$ is the velocity of wave transmition.
- $U$ is convective velocity, which is constant here.

Then we can expand the governing equation using material derivative:
\[
\frac{\partial^2 \psi}{\partial t^2} + 2U \frac{\partial^2 \psi}{\partial t \partial x} - \left(c_0^2 - U^2\right) \frac{\partial^2 \psi}{\partial x^2}
= 0
\]

## 2. Analytical solution 

We also use Gaussian function as the initial condition in this case. 

\[
\psi(x,0) = \exp\left[-\alpha (x - x_0)^2\right],\qquad
\left.\frac{\partial \psi}{\partial t}\right|_{t=0} = 0
\]

Assume the solution is such form:

\[
\psi(x,t)=f\big(x - (U + c_0)t\big)+ g\big(x - (U - c_0)t\big)
\]

The Analytical solution is:

\[
\boxed{
\psi(x,t) =
\frac{1}{2}
\left[
\exp\left(-\alpha \big(x - (U + c_0)t - x_0\big)^2\right)
+
\exp\left(-\alpha \big(x - (U - c_0)t - x_0\big)^2\right)
\right]
}
\]