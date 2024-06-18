# PetPal

PetPal ist ein virtuelles Haustier-Spiel, das in C++ und Qt entwickelt wurde. Das Projekt zielt darauf ab, eine interaktive und lehrreiche Erfahrung zu bieten, indem es die Benutzer dazu ermutigt, sich um ihr virtuelles Haustier zu kümmern, es zu trainieren und mit ihm zu interagieren.

## Projektziele

1. **Virtuelles Haustier erstellen und pflegen**: Benutzer können ein neues Haustier erstellen, es füttern, streicheln und trainieren, um seine Gesundheit, Glück und Hunger zu verwalten.
2. **Anpassung des Haustiers**: Benutzer können das Aussehen ihres Haustiers anpassen, indem sie Farben, Muster und Accessoires auswählen.
3. **Erweiterte Interaktionen**: Das Haustier kann Emotionen entwickeln und auf Benutzerinteraktionen sowie auf Wetteränderungen reagieren.
4. **Bildungsinhalte**: Das Spiel integriert lehrreiche Informationen über Tierpflege und -gesundheit.

## Funktionen

### Hauptfunktionen

1. **Neues Haustier erstellen**: Benutzer können ein neues Haustier erstellen, indem sie Art, Name und andere Eigenschaften auswählen.
2. **Haustier füttern und streicheln**: Benutzer können das Haustier füttern und streicheln, um seine Bedürfnisse zu erfüllen.
3. **Haustier trainieren**: Benutzer können ihrem Haustier Tricks beibringen und Minispiele spielen, um seine Fähigkeiten zu verbessern.
4. **Speichern und Laden**: Der aktuelle Zustand des Haustieres kann gespeichert und später wieder geladen werden.

### Erweiterte Funktionen

1. **Emotionale Zustände**: Das Haustier zeigt emotionale Reaktionen basierend auf der Pflege durch den Benutzer.
2. **Claude API Integration**: Das Haustier kann mittels einer fortgeschrittenen AI mit dem Benutzer kommunizieren.
3. **Wetterabhängige Aktivitäten**: Das aktuelle Wetter beeinflusst die Aktivitäten und Stimmungen des Haustieres.
4. **Lernfähigkeit**: Das Haustier lernt aus den Interaktionen mit dem Benutzer und passt sein Verhalten entsprechend an.

## Systemanforderungen

1. **GUI**: Das System bietet eine grafische Benutzeroberfläche, die die Verwaltung und Anzeige der Statuswerte des Haustieres ermöglicht.
2. **Datenstrukturen**: Generische Templates werden verwendet, um flexible Listen von Haustieren zu speichern.
3. **Fehlerbehandlung**: Robuste Fehlerbehandlung wird durch Try-Catch-Blöcke sichergestellt.
4. **Datenströme**: Input/Output-Streams werden für das Lesen und Schreiben von Haustierdaten verwendet.
5. **Threads**: Hintergrundaufgaben wie das Update der Statuswerte nutzen Threads.

## Installationsanleitung

1. **Voraussetzungen**:
   - C++20 Compiler
   - Qt 6 Framework
   - Internetverbindung für die Wetter-API und Claude API

2. **Schritte**:
   1. Repository klonen:
      ```sh
      git clone https://github.com/dein-benutzername/PetPal.git
      ```
   2. Abhängigkeiten installieren:
      ```sh
      cd PetPal
      qmake PetPal.pro
      make
      ```
   3. Anwendung starten:
      ```sh
      ./PetPal
      ```

## Nutzung

1. **Anwendung starten**: Führen Sie die Anwendung aus, um den Startbildschirm anzuzeigen.
2. **Neues Haustier erstellen**: Wählen Sie "Neues Haustier erstellen" und geben Sie die Details für Ihr Haustier ein.
3. **Haustier verwalten**: Nutzen Sie die Optionen im Hauptbildschirm, um Ihr Haustier zu füttern, zu streicheln, zu trainieren und anzupassen.
4. **Speichern und Laden**: Speichern Sie den Zustand Ihres Haustieres und laden Sie ihn später wieder, um fortzufahren.

## Lizenz

Dieses Projekt ist unter der MIT-Lizenz lizenziert.