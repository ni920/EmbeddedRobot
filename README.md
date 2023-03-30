# EmbeddedRobot
Projekt zu Embedded System Master Wahlfach KI/PI HTW Saar 

- [EmbeddedRobot](#embeddedrobot)
  - [Ziel des Projektes](#ziel-des-projektes)
  - [Spielablauf](#spielablauf)
  - [Analyse der Software](#analyse-der-software)
  - [Arbeiten mit dem Roboter](#arbeiten-mit-dem-roboter)
    - [Bauen des Projektes](#bauen-des-projektes)
    - [Hochladen zum Roboter](#hochladen-zum-roboter)
      - [EV3Duder](#ev3duder)



## Ziel des Projektes

Ziel des Projektes war es, in Teams einen Roboter (Lego Mindstorms) zu entwickeln, dessen Steuerungssoftware aktuellen Industrierichtlinien fur sicherheitskritischen C-Code entspricht.

Die Roboterentwicklung soll typische Arbeitsprozesse der Entwicklung (sicherheitskritischer) eingebetteter System nachspielen. Besonderes Augenmerk wird hierbei auf Verifikations- und Validierungsphasen gelegt.

## Spielablauf

Ballkicker ist ein einfaches Zweipersonenspiel bzw. Zweiroboterspiel, bei dem es darum geht, nach
einem festen Regelwerk Bälle von einem Tisch zu entfernen und bei dem der Spieler oder Roboter
gewinnt, der den letzten Ball vom Tisch kickt.

**Regelwerk** 

Beide Spieler entfernen abwechselnd Balle vom Tisch, nach den folgenden Regeln: 

  * ist die Anzahl der noch auf dem Tisch befindlichen Ballen eine Primzahl, darf der Spieler einen oder zwei Balle vom Tisch stoßen,
  * ansonsten muss genau ein (1) Ball vom Tisch entfernt werden.

Sobald der Roboter am Zug ist (unabhängig davon, wer zuerst anfängt) wird dieser aktiviert. 
In jeder Runde soll der Roboter dann die Anzahl der Bälle bestimmen, die vorberechnete Anzahl an Bällen vom Tisch stoßen, auf seine Startposition zurückkehren und ein Ende der Runde signalisieren.

Das Spielfeld, das Aussehen, sowie die genaue Funktionsweise des Roboters ist frei wahlbar.

Zum Zahlen der Bälle kann der Infrarotsensors verwendet werden. Hierzu muss der Roboter eine bestimmte Strecke abfahren und die Anzahl der Objekte bzw. der Lücken zählen. 

Rundenende sowie Sieg/Niederlage des Roboters kann mittels der Soundausgabe signalisiert werden.

Die vorberechnete optimale Strategie kann fest in die Ablaufsteuerung des Roboters einprogrammiert
werden.

## Analyse der Software

Analysiert wurde die Steuersoftware mit Astree. 

Es wurde mittels statischer Quellcodeanalyse gezeigt, dass die Software MISRA-konform programmiert wurde.

## Arbeiten mit dem Roboter

### Bauen des Projektes

Gebaut kann das Projekt über Eclipse für C werden in Windows.

### Hochladen zum Roboter


| Was            | System                    | Status |
| -------------- | ------------------------- | ------ |
| Plugin Eclipse | Windows                   | ✅     |
| Plugin Eclipse | Mac                       | ❌     |
| Plugin Eclipse | Ubuntu                    | ❌     |
| Ev3Duder       | Mac                       | ❌     |
| Ev3Duder       | Ubuntu                    | ✅     |
| Ev3Duder       | Windows (Ubuntu Terminal) | ❌     |




#### EV3Duder

+ https://github.com/c4ev3/ev3duder
+ Schritte in Readme befolgen https://github.com/c4ev3/ev3duder/blob/master/README.md#uploading
+ Test Upload https://github.com/c4ev3/ev3duder/blob/master/README.md#tests


