# UVa 12765 FactorialProducts

   * %%URL%%

## Categories

   * Maths; factorial/factorisation.

## Approach

Adopt an "anagramatic" approach. Bin each product into it's composites. Initially, I thought 
that you could just bin directly into the factors and count these (i.e. 1 2 3 4 5 etc.) but
this doesn't really work. A key insight is that you need to bin into prime factors, not
composites. The range of numbers is really small though, so the largest prime is 7. This
factorisation can be done statically.

Once you have two "fingerprints" then compare them for equality.

## Hints

   * Count the prime factors.

## Optimisations

   * Input optimisation.
   * Loop splitting on binning.
   * Direct factor calculation.
