# Precalculation of factorial and multiplicative inverses

# For example nCr % mod = n!/(r! * (n-r)!) % mod   then we need n! % mod as well as inverse facorials of r! and (n-r)! 

# We can precalculate these in O(n) and can give answer per test case in O(1)


fac=[1]*N
inv=[1]*N

# Precalculating multiplicative inverse of 1,2,.... n 
# This formula is derived using Dividend=Divisor*Quotient+Remainder
# For more details go to this blog :- http://codeforces.com/blog/entry/5457


for i in xrange(2,N):
    inv[i]=(mod-mod/i)*inv[mod%i] % mod    
    
# Calculating x! and multiplicative inverse of x!  where x=2..N    

for i in xrange(2,N):
    fac[i]=fac[i-1]*i % mod
    inv[i]=inv[i-1]*inv[i] % mod
