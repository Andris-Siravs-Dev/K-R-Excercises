#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    	// === TEIL 1: AUSGABE ÜBER STANDARD-DEFINITIONSATEIEN ===
    	printf("=== Werte aus <limits.h> und <float.h> ===\n");

    	printf("char:          %d bis %d\n", CHAR_MIN, CHAR_MAX);
    	printf("unsigned char: 0 bis %u\n", UCHAR_MAX);

    	printf("short:         %d bis %d\n", SHRT_MIN, SHRT_MAX);
    	printf("unsigned short:0 bis %u\n", USHRT_MAX);

    	printf("int:           %d bis %d\n", INT_MIN, INT_MAX);
	printf("unsigned int:  0 bis %u\n", UINT_MAX);

	printf("long:          %ld bis %ld\n", LONG_MIN, LONG_MAX);
	printf("unsigned long: 0 bis %lu\n\n", ULONG_MAX);

	printf("float:         %e bis %e\n", FLT_MIN, FLT_MAX);
	printf("double:        %e bis %e\n\n", DBL_MIN, DBL_MAX);

    	// === TEIL 2: DIREKTE BERECHNUNG ===
   	printf("=== Direkte Berechnung (Ganzzahlen) ===\n");

    	// Unsigned Werte berechnen (Alle Bits auf 1 setzen via Bit-Inversion)
    	unsigned char uc_max  = (unsigned char)~0;
	unsigned short us_max = (unsigned short)~0;
    	unsigned int ui_max   = (unsigned int)~0;
    	unsigned long ul_max  = (unsigned long)~0;

    	// Signed Werte über Bit-Verschiebung berechnen (Zweierkomplement)
    	// MAX: Das Vorzeichenbit wird auf 0 gesetzt, alle anderen auf 1.
    	// MIN: Das bitweise Komplement des Maximums (liefert den korrekten negativen Wert)
    	signed char sc_max = (signed char)(uc_max >> 1);
    	signed char sc_min = (signed char)~sc_max;

    	short ss_max = (short)(us_max >> 1);
    	short ss_min = (short)~ss_max;

    	int si_max = (int)(ui_max >> 1);
    	int si_min = (int)~si_max;

    	long sl_max = (long)(ul_max >> 1);
    	long sl_min = (long)~sl_max;

    	printf("Calc char:          %d bis %d\n", sc_min, sc_max);
    	printf("Calc unsigned char: 0 bis %u\n", uc_max);
    	printf("Calc short:         %d bis %d\n", ss_min, ss_max);
    	printf("Calc unsigned short:0 bis %u\n", us_max);
    	printf("Calc int:           %d bis %d\n", si_min, si_max);
    	printf("Calc unsigned int:  0 bis %u\n", ui_max);
    	printf("Calc long:          %ld bis %ld\n", sl_min, sl_max);
    	printf("Calc unsigned long: 0 bis %lu\n", ul_max);

    return 0;
}
