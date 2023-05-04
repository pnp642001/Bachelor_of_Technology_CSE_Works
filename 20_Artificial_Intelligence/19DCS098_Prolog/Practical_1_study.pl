
% teaches(X,Y): Person X teaches subject Y

teaches(ram,ai).
teaches(rahul,os).
teaches(narendra,android).
teaches(amit,networks).
teaches(paul,hss).

% studies(Z,Y): Student Z studies subject Y

studies(parth,android).
studies(parth,ai).
studies(roshan,networks).
studies(arthur,hss).
studies(krishna,ai).
studies(het,os).
studies(jack,hss).
studies(henry,android).

% Rule : professor(X,Y,Z): X is professor of Z if X teaches Y and Z
% studies the subject that X teaches.


professor(X,Y,Z):- teaches(X,Y),studies(Z,Y).


