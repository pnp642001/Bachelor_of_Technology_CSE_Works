animal(dog).
animal(elephant).
animal(tiger).
animal(cobra).
animal(python).
animal(blackMamba).

snake(cobra).
snake(python).
snake(blackMamba).

likes(raj,X):- snake(X),!,fail.
likes(raj,X):- animal(X).
