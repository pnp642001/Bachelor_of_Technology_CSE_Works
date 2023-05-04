go :-
    write('What is the patient''s name? '),
    read(Patient),
    hypothesis(Patient,Disease),
    write_list([Patient,'probably has ',Disease,'.']),nl.

go :-
    write('Sorry, I don''t seem to be able to'),nl,
    write('diagnose the disease.'),nl.

symptom(Patient,fever) :-
    write_list(['Does ',Patient,' have a fever (y/n) ?']),
    response(Reply),
    Reply='y'.

symptom(Patient,rash) :-
    write_list(['Does ',Patient,' have a rash (y/n) ?']),
    response(Reply),
    Reply='y'.

symptom(Patient,headache) :-
    write_list(['Does ',Patient,' have a headache (y/n) ?']),
    response(Reply),
    Reply='y'.

symptom(Patient,runny_nose) :-
    write_list(['Does ',Patient,' have a runny_nose (y/n) ?']),
    response(Reply),
    Reply='y'.

symptom(Patient,conjunctivitis) :-
    write_list(['Does ',Patient,' have a conjunctivitis (y/n) ?']),
    response(Reply),
    Reply='y'.

symptom(Patient,cough) :-
    write_list(['Does ',Patient,' have a cough (y/n) ?']),
    response(Reply),
    Reply='y'.

symptom(Patient,body_ache) :-
    write_list(['Does ',Patient,' have a body_ache (y/n) ?']),
    response(Reply),
    Reply='y'.

symptom(Patient,chills) :-
    write_list(['Does ',Patient,' have a chills (y/n) ?']),
    response(Reply),
    Reply='y'.

symptom(Patient,sore_throat) :-
    write_list(['Does ',Patient,' have a sore_throat (y/n) ?']),
    response(Reply),
    Reply='y'.

symptom(Patient,sneezing) :-
    write_list(['Does ',Patient,' have a sneezing (y/n) ?']),
    response(Reply),
    Reply='y'.

symptom(Patient,swollen_glands) :-
    write_list(['Does ',Patient,' have a swollen_glands (y/n) ?']),
    response(Reply),
    Reply='y'.

hypothesis(Patient,measles) :-
    symptom(Patient,fever),
    symptom(Patient,cough),
    symptom(Patient,conjunctivitis),
    symptom(Patient,runny_nose),
    symptom(Patient,rash).

hypothesis(Patient,german_measles) :-
    symptom(Patient,fever),
    symptom(Patient,headache),
    symptom(Patient,runny_nose),
    symptom(Patient,rash).

hypothesis(Patient,flu) :-
    symptom(Patient,fever),
    symptom(Patient,headache),
    symptom(Patient,body_ache),
    symptom(Patient,conjunctivitis),
    symptom(Patient,chills),
    symptom(Patient,sore_throat),
    symptom(Patient,runny_nose),
    symptom(Patient,cough).

hypothesis(Patient,common_cold) :-
    symptom(Patient,headache),
    symptom(Patient,sneezing),
    symptom(Patient,sore_throat),
    symptom(Patient,runny_nose),
    symptom(Patient,chills).

hypothesis(Patient,mumps) :-
    symptom(Patient,fever),
    symptom(Patient,swollen_glands).

hypothesis(Patient,chicken_pox) :-
    symptom(Patient,fever),
    symptom(Patient,chills),
    symptom(Patient,body_ache),
    symptom(Patient,rash).

hypothesis(Patient,measles) :-
    symptom(Patient,cough),
    symptom(Patient,sneezing),
    symptom(Patient,runny_nose).

write_list([]).
write_list([Term| Terms]) :-
    write(Term),
    write_list(Terms).

response(Reply) :-
    get_single_char(Code),
    put_code(Code), nl,
    char_code(Reply, Code).
