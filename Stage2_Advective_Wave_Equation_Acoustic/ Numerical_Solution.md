# 1D Advective Wave Equation numerical solution

## 1. Governing Equation
Material derivation
\[
\frac{D}{Dt} = \frac{\partial}{\partial t} + U \frac{\partial}{\partial x}
\]


\[
\frac{D^2 \psi}{Dt^2} - c_0^2 \frac{\partial^2 \psi}{\partial x^2} = 0
\]

1-D Form：

\[
\frac{\partial^2 \psi}{\partial t^2} + 2U \frac{\partial^2 \psi}{\partial t \partial x} - (c_0^2 - U^2)\frac{\partial^2 \psi}{\partial x^2}
= 0
\]

---

## 2. Temporal scheme：Leapfrog
**Leapfrog**：

\[
\frac{\partial^2 \psi}{\partial t^2}
\approx
\frac{\psi_i^{n+1} - 2\psi_i^n + \psi_i^{n-1}}{\Delta t^2}
\]

---

## 4. Spatial scheme

### 4.1 \( \partial^2 \psi / \partial t \partial x \)

Central for both time and space：

\[
\frac{\partial^2 \psi}{\partial t \partial x}\approx
\frac{
(\psi_{i+1}^n - \psi_{i-1}^n)-
(\psi_{i+1}^{n-1} - \psi_{i-1}^{n-1})
}{
2 \Delta x \Delta t
}
\]

---

### 4.2  \( \partial^2 \psi / \partial x^2 \)

Central：

\[
\frac{\partial^2 \psi}{\partial x^2}
\approx
\frac{\psi_{i+1}^n - 2\psi_i^n + \psi_{i-1}^n}{\Delta x^2}
\]

---

## 5. Discretization


\[
\psi_i^{n+1}
= 2\psi_i^n - \psi_i^{n-1} - U \frac{\Delta t}{2\Delta x}
\left[
(\psi_{i+1}^n - \psi_{i-1}^n) -
(\psi_{i+1}^{n-1} - \psi_{i-1}^{n-1})
\right]
+
(c_0^2 - U^2)
\frac{\Delta t^2}{\Delta x^2}
(\psi_{i+1}^n - 2\psi_i^n + \psi_{i-1}^n)
\]
