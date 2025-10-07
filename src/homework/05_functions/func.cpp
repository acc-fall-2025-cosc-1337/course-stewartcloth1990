//add include statements
#include <iostream>
#include "func.h"

//add function code here

// Calculates the GC content of a given DNA string.
double get_gc_content(const string& dna)
{
    double gc_count = 0.0;

    for (char nucleotide : dna)
    {
        if (nucleotide == 'G' || nucleotide == 'C')
        {
            gc_count += 1.0;
        }
    }
    return gc_count / dna.length();
}


// Function to reverse a given DNA string
string get_reverse_string(string dna)
{
    string reversed = "";

    for (int i = dna.length() -1; i >= 0; --i)
    {
        reversed += dna[i];
    }
    return reversed;
}

// Function to get the DNA complement
string get_dna_complement(string dna)
{
    string complement = "";

    complement.reserve(dna.size());

    // Compute complement (reverse first, then complement each base)
    for (auto it = dna.rbegin(); it != dna.rend(); ++it)
    {
        switch (*it)
        {
            case 'A': 
                complement += 'T';
                break;

            case 'T': 
                complement += 'A'; 
                break;

            case 'C': 
                complement += 'G'; 
                break;

            case 'G': 
                complement += 'C'; 
                break;

            default: 
                complement += *it; 
                break;
        }
    }
    return complement;
}