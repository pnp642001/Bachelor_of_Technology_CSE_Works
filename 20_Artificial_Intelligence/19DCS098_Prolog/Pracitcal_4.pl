
male(tom).
male(jerry).
male(harry).
male(sunny).
male(balmar).
female(anne).
female(jenna).
female(arthur).
female(jake).
female(granny).
male(barry).
male(goffy).
female(goffy).
parent(sunny,jerry).
parent(sunny,harry).
parent(sunny,anne).
parent(jenna,jerry).
parent(jenna,harry).
parent(jenna,anne).
parent(balmar,sunny).
parent(jake,sunny).
parent(arthur,jenna).
parent(arthur,tom).
parent(granny,arthur).
parent(jerry,barry).
male(milan).
male(tino).
parent(rahul,milan).
parent(rahul,tino).
indian(anne).
indian(X) :- ancestor(X,anne).
indian(X) :- ancestor(anne,X).
relation(X,Y) :- ancestor(A,X), ancestor(A,Y).
father(X,Y) :- male(X),parent(X,Y).
father(goffy, _) :- male(goffy).
mother(X,Y) :- female(X),parent(X,Y).
son(X,Y) :- male(X),parent(Y,X).
daughter(X,Y) :- female(X),parent(Y,X).
grandfather(X,Y) :- male(X),parent(X,Somebody),parent(Somebody,Y).
aunt(X,Y) :- female(X),sister(X,Mom),mother(Mom,Y).
aunt(X,Y) :- female(X),sister(X,Dad),father(Dad,Y).
sister(X,Y) :- female(X),parent(Par,X),parent(Par,Y), X \= Y.
uncle(X,Y) :- brother(X,Par),parent(Par,Y).
cousin(X,Y) :- uncle(Unc , X),father(Unc,Y).
ancestor(X,Y) :- parent(X,Y).
ancestor(X,Y) :- parent(X,Somebody),ancestor(Somebody,Y).
brother(X,Y) :- male(X),parent(Somebody,X),parent(Somebody,Y), X \= Y.
