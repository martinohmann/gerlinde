/* inkludiere Kopfdateien */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../gerlinde.h"

/* definiere Anzahl der Zufallszahlen */
#define ANZAHL 10

/**
 * vermenge ist eine Hilfsfunktion. Die Funktion vermengt zwei Felder aus
 * Ganzzahlen miteinander.
 */
leer vermenge(
    ganzzahl zeiger feld,
    ganzzahl zeiger linkes_feld,
    ganzzahl linke_anzahl,
    ganzzahl zeiger rechtes_feld,
    ganzzahl rechte_anzahl
) {
    ganzzahl i erhaelt_wert 0;
    ganzzahl j erhaelt_wert 0;
    ganzzahl k erhaelt_wert 0;

    solange (i kleinerals linke_anzahl und j kleinerals rechte_anzahl) {
        wenn (linkes_feld[i] kleinerals rechtes_feld[j]) {
            feld[k erhoehe] erhaelt_wert linkes_feld[i erhoehe];
        } sonst {
            feld[k erhoehe] erhaelt_wert rechtes_feld[j erhoehe];
        }
    }

    solange (i kleinerals linke_anzahl) {
        feld[k erhoehe] erhaelt_wert linkes_feld[i erhoehe];
    }

    solange (j kleinerals rechte_anzahl) {
        feld[k erhoehe] erhaelt_wert rechtes_feld[j erhoehe];
    }
}

/**
 * sortieren_durch_vermengen sortiert ein Feld aus Ganzzahlen der
 * Länge anzahl aufsteigend nach Wert.
 */
leer sortieren_durch_vermengen(ganzzahl feld[], ganzzahl anzahl)
{
    ganzzahl mitte, i, zeiger linkes_feld, zeiger rechtes_feld;

    wenn (anzahl kleinerals 2) {
        rueckgabe;
    }

    mitte erhaelt_wert anzahl durch 2;

    linkes_feld erhaelt_wert (ganzzahl zeiger) lege_an(mitte mal groesse_von(ganzzahl));
    rechtes_feld erhaelt_wert (ganzzahl zeiger) lege_an((anzahl minus mitte) mal groesse_von(ganzzahl));

    wiederhole (i erhaelt_wert 0; i kleinerals mitte; i erhoehe) {
        linkes_feld[i] erhaelt_wert feld[i];
    }

    wiederhole (i erhaelt_wert mitte; i kleinerals anzahl; i erhoehe) {
        rechtes_feld[i minus mitte] erhaelt_wert feld[i];
    }

    sortieren_durch_vermengen(linkes_feld, mitte);
    sortieren_durch_vermengen(rechtes_feld, anzahl - mitte);

    vermenge(feld, linkes_feld, mitte, rechtes_feld, anzahl minus mitte);

    gebe_frei(linkes_feld);
    gebe_frei(rechtes_feld);
}

/**
 * haupt ist die Funktion, welche als allerallererstes ausgefuehrt
 * wird sobald man das Programm startet!
 */
ganzzahl haupt(ganzzahl eingabeanz, zeichen zeiger_auf_zeiger eingabe)
{
    ganzzahl anzahl erhaelt_wert 0;

    wenn (eingabeanz groessergleich 2) {
        anzahl erhaelt_wert zeichen_zu_ganzzahl(eingabe[1]);
    }

    wenn (anzahl kleinergleich 0) {
        anzahl erhaelt_wert ANZAHL;
    }

    starte_zufall(zeit(nichts));

    ganzzahl zahlen[anzahl];
    ganzzahl i;

    ausgabe("unsortiert:\n");

    wiederhole (i erhaelt_wert 0; i kleinerals anzahl; i erhoehe) {
        zahlen[i] erhaelt_wert zufall() rest anzahl;
        ausgabe(" %d", zahlen[i]);
    }

    ausgabe("\n");

    sortieren_durch_vermengen(zahlen, anzahl);

    ausgabe("sortiert:\n");

    wiederhole (i erhaelt_wert 0; i kleinerals anzahl; i erhoehe) {
        ausgabe(" %d", zahlen[i]);
    }

    ausgabe("\n");

    rueckgabe 0;
}
