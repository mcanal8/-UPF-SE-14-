# README #


Q1.
What do you see in the command screen?

Per pantalla el programa ens notifica que no s'ha afegit res per actualitzar, i també ens indica que el branch està up to date amb l'original.
-------------------------------------------------------------------------------------------------------------------------------------------------------
Q2.
Use the command git status again and explain what has changed?

En aquest cas llista l'arxiu README.md com a modificat, pero encara no actualitzat al repositori.
-------------------------------------------------------------------------------------------------------------------------------------------------------
Q3.
What is the output of the command? What is the current status?

A l'output ens indica el contingut nou que hem afegit en l'última edició de l'arxiu amb el text de color verd. Al escriure la comanda git status ens mostra com a modificat l'arxiu README.md.
-------------------------------------------------------------------------------------------------------------------------------------------------------
Q4.
What can be a good message for the first commit? What is the current status?

Creiem que un bon missatge sería ex1.9FirstCommit, ja que indiquem el motiu del commit (l'exercici 1.9).
En el nou status ja no hi han canvis pendents de ser pujats al repositori, la modificació del README.md que hi havia pendent ha desaparegut.
-------------------------------------------------------------------------------------------------------------------------------------------------------
Q5.
How many commits there are in the log? What are the first seven digits (letters and numbers) that identify the first README.md commit?

Hi han dos commits en el log. Creiem que es l'identificador que s'utilitza al repositori per diferenciar els diferents comits.

We are in documents branch.


Q6. 
Modify one line of the README.md, add to the staging area and commit. Then use the command git show HEAD, and explain the output.

Aquesta comanda retorna tota la informació sobre l'últim commit: Data, informació del commit com l'id, llista de modificacions.
-------------------------------------------------------------------------------------------------------------------------------------------------------
Q7.Run a reset in the README.md and explain what happens.

En fer un reset de README pel commit HEAD, es pot veure, utilitzant git status, que el fitxer README.md ha estat modificat a la staging area. No obstant, al directori tot segueix igual.
--------------------------------------------------------------------------------------------------------------------------------------------------------
Q8. 
Create a new branch called “documents”. Use git branch and explain where you are
and how many branches you have?

Després d'aplicar aquestes comandes es pot veure que tenim 2 branch, i que concretament ens trobem a la branch "master".
--------------------------------------------------------------------------------------------------------------------------------------------------------
Q9.
What is the content of the README.md in both branches?

El fitxer README.md de la branch documents conté la frase "We are in documents branch".
En canvi, el fitxer README.md de la master branch conté el que hi havia al fitxer abans de modificar-lo.
---------------------------------------------------------------------------------------------------------------------------------------------------------
Q10.
Then move to the “master” branch and merge the “documents” branch. 
Do you have conflicts? In case there areconflicts, explain how can you solve them. 
The aim is to finish the merge successfully.

Sí, diu que hi ha un conflicte en el fitxer README.md. 









