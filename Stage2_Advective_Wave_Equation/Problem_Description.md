# Stage 2：One-Dimensional advective wave equation

## 1. Governing equation

\[
\frac{\partial u}{\partial t} + a\,\frac{\partial u}{\partial x} = 0
\]


- \(u(x,t)\) is velocity
- \(a\) is advective velocity

---

## 2. Initial condition

Consider the initial condition

\[
u(x,0) = u_0(x)
\]

In this case:

\[
u(x,0) = \exp\left[-100(x-0.3)^2\right]
\]

---

## 3. Analytical solution

This equation can be solved by method of characteristic line

The characteristic line ：

\[
\frac{dx}{dt} = a
\]

Along this line：

\[
\frac{du}{dt} = 0
\]

Therefore：

\[
\boxed{
u(x,t) = u_0(x - a t)
}
\]

---

## 4. In this problem

The final solution is：

\[
\boxed{
u(x,t) = \exp\left[-100(x - a t - 0.3)^2\right]
}
\]

This solution represents：
- This initial wave transmit with convective velocity \(a\) toward \(x\)
- The shape of the wave remains unchanged 
- No dispersion and dissipation 

---

## 5. Numerical solution
- If the wave becomes low and broad, it represents numerical dissipation
- If it occurs oscillation, it represents numerical dispersion
- Stablity

---