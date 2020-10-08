def isPrime(n):
    if n == 2:
        prime = True
    else:
        if n == 1 or n % 2 == 0:
            prime = False
        else:
            prime = True
            nat = 3                
            while nat*nat <= n and prime:
                if n % nat == 0:    
                    prime = False
                nat = nat + 2
    return prime