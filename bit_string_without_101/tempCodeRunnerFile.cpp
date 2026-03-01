sol[len] = 0;
            solve(len+1, isContain);
            sol[len] = 1;
            solve(len+1, isContain);