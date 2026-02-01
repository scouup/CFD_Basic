# Stage 2：von Neumann Stablity analysis

## 1. Governing equation

1-D advective wave equation：

\[
\frac{\partial u}{\partial t} + a\,\frac{\partial u}{\partial x} = 0
\]

其中：
- \(a > 0\) advective velocity
- \(u(x,t)\) velocity

---

CFL number：
\[
\boxed{
\text{CFL} = \frac{a\,\Delta t}{\Delta x}
}
\]

---

## 3. Temporal Discretization（Euler - Explicit）

时间导数统一采用显式 Euler：

\[
\frac{\partial u}{\partial t}
\approx
\frac{u_i^{n+1} - u_i^n}{\Delta t}
\]

---

## 4. Spatial discretization

### 4.1 1st-order（Upwind, \(a>0\)）

Spatial derivative：

\[
\frac{\partial u}{\partial x}
\approx
\frac{u_i^n - u_{i-1}^n}{\Delta x}
\]

Put it into governing equation：

\[
u_i^{n+1} =
u_i^n -
\text{CFL}\,
\left(
u_i^n - u_{i-1}^n
\right)
\]

---

### 4.2 1st-order（Downwind）

Spatial derivative：

\[
\frac{\partial u}{\partial x}
\approx
\frac{u_{i+1}^n - u_i^n}{\Delta x}
\]

Put it into governing equation：

\[
u_i^{n+1} =
u_i^n -
\text{CFL}\,
\left(
u_{i+1}^n - u_i^n
\right)
\]

---

### 4.3 2nd-order（Central）

Spatial derivative：

\[
\frac{\partial u}{\partial x}
\approx
\frac{u_{i+1}^n - u_{i-1}^n}{2\Delta x}
\]

Put it into governing equation：

\[
u_i^{n+1} =
u_i^n -
\frac{\text{CFL}}{2}
\left(
u_{i+1}^n - u_{i-1}^n
\right)
\]

---

## 5. von Neumann Stability analysis

Assume the solution can be represent the Fourier mode：

\[
u_i^n = G^n e^{ikx_i}
\]

- \(G\)：amplified factor
- \(k\)：wavenumber

Stable condition：

\[
\boxed{
|G| \le 1
}
\]

---

## 6. The amplified factor of each scheme

### 6.1 1st-order upwind
\[
G =
1 - \text{CFL}
\left(
1 - e^{-ik\Delta x}
\right)
\]

---
\[
|G|^2 =
(1-\text{CFL})^2 + 2\text{CFL}(1-\text{CFL})\cos(k\Delta x)+\text{CFL}^2
\]

Stable condition：

\[
\boxed{
0 \le \text{CFL} \le 1
}
\]

**Conclusion**：
- CFL ≤ 1 is stable
- G is less than 1; therefore, this scheme has numerical dissipation

---

### 6.2 1st-order downwind

Amplified factor：

\[
G=1-
\text{CFL}
\left(
e^{ik\Delta x} - 1
\right)
\]

---

\[
|G| > 1 \quad \forall\ \text{CFL} > 0
\]

**Conclusion**：
- It is unconditional unstable


---

### 6.3 2nd-order central

Amplified factor：

\[
G=1-
i\,\text{CFL}\,\sin(k\Delta x)
\]

---

\[
|G|=
\sqrt{
1 + \text{CFL}^2 \sin^2(k\Delta x)
}>1
\]

**Conclusion**：

\[
\boxed{
\text{Central + Explicit：Unconditional unstable}
}
\]

表现为：
- No Dissipation
- Strong dispersion

---
