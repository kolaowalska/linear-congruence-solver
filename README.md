This program is a C++ implementation of a solver for linear Diophantine equations.

Finding all possible values of $x$ in $\mathbb{Z}_n$ satisfying the linear congruence $a \cdot x \equiv b \ (\text{mod} \ n)$ is equivalent to solving the equation $a \cdot x = b + k \cdot n$, where $k$ is any integer and the solution is valid modulo $n$. A solution exists if and only if the GCD of $a$ and $n$, divides $b$. It is then possible to simplify the equation and divide $\(a, b, n\)$ by $\text{GCD}\(a, n\)$ to form a reduced congruence $a' \cdot x \equiv b' \ (\text{mod} \ n')$. Having computed the modular inverse of $a' (\text{mod} \ n')$ using the Extended Euclidean Algorithm, we can use this inverse to find a particular solution $x_0$, and then generalize the solution set $x = x_0 + k \cdot n$ for $k \in \\{0, 1, \ldots, GCD(a, n) - 1\\}$.

This is done with the help of the following functions: 
* `extendedGCD(a, b)` computes the GCD of `a` and `b` using the extended Euclidean algorithm. It additionally returns coefficients `x` and `y` such that $a \cdot x + b \cdot y = \text{GCD}(a, b)$.
* `inverse(a, n)` computes the modular inverse of `a` modulo `n` using extended GCD algorithm to verify its existence.
* `linsolve(a, b, n)` solves the linear congruence $a \cdot x \equiv b \ (\text{mod} \ n)$; if solutions exist, it computes and prints all possible solutions modulo $n$.

All arithmetic has been simplified to assume values within the range of standard C++ `long long` but can be easily modified to handle larger integers using the GMP Arithmetic Library.
