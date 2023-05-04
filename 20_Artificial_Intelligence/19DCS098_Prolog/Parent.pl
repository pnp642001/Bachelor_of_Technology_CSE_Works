
%parent(name,name)
%male(name)
%female(name)
%mother(name,name)
%father(name,name)
%child(name,name)
%brother(name,name,name,name)
%sister(name,name,name,name)
%hasChild(name,name)

%male

male(jim).
male(bob).
male(tom).
male(peter).

%female

female(penny).
female(liza).
female(anna).
female(alisa).

%parent(X,Y)

parent(penny,bob).
parent(tom,liza).
parent(tom,bob).
parent(bob,anna).
parent(bob,alisa).
parent(penny,jim).
parent(bob,peter).
parent(peter,jim).

%rules

mother(X,Y):- parent(X,Y),female(X).
father(X,Y):- parent(X,Y),male(X).
hasChild(X):- parent(X,_).
sister(X,Y):- parent(Z,X),parent(Z,Y),female(X),X\==Y.
brother(X,Y):- parent(Z,X),parent(Z,Y),male(X),X\==Y.
