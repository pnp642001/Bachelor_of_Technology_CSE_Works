
%FACTS
person(harry,male).
person(jenna,female).
person(tom,male).
person(cortney,female).
person(sam,male).
person(michelle,female).
person(robin,male).
person(jenny,female).
person(sunny,male).
person(cherry,female).

%Rule

couple(X,Y):- person(X,male),person(Y,female).



