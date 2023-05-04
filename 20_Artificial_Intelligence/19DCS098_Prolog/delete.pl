delete(X,[X|T],T).

delete(X,[H|T],[H|T1]):-
    delete(X,T,T1).

