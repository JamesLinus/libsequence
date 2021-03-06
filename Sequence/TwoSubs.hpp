/*

  Copyright (C) 2003-2009 Kevin Thornton, krthornt[]@[]uci.edu

  Remove the brackets to email me.

  This file is part of libsequence.

  libsequence is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  libsequence is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  long with libsequence.  If not, see <http://www.gnu.org/licenses/>.

*/

#ifndef TWOSUBS_H
#define TWOSUBS_H
#include <Sequence/SeqEnums.hpp>
#include <Sequence/WeightingSchemes.hpp>
#include <string>
#include <memory>
/*! \file TwoSubs.hpp Sequence/TwoSubs.hpp
  @brief used by Sequence::Comeron95, class Sequence::TwoSubs calculates divergence between codons that differ at two sites
*/
/*!
  \class Sequence::TwoSubs
  \ingroup kaks
  \image html 2subs.jpg "Pathways when codons differ at 2 sites"
  \image latex 2subs.pdf "Pathways when codons differ at 2 sites" width=6cm
  each branch can have a weighting scheme, x_i\n
  the correct weights to apply to changes for each path are:\n
  p1 = changes on b1 + changes on b2\n
  p2 = changes on b3 + changes on b4\n
    
  A function object to obtain divergence statistics for Comeron's method for codons that differ at two positions.
  Alternate paths are weighted by Grantham's distances. Used by Sequence::Comeron95.
 
  \note In the above figure, codon1 and intermediate1 differ at the first of the 2 substitued
  sites (either the first or second codon position).  Likewise, codon1 and intermedate2 differ
  at the seconf of the 2 substituted positions (i.e. the second or the third codon position).
  This is important information, because if you want to implement your own scheme to weight these
  pathways (done by deriving a class from Sequence::WeightingScheme2 and Sequence::WeightingScheme3),
  you must know how this class names and assigns the intermediate steps and the branches.  In other 
  words, you must study the implementation of this class.  You may also want to refer to the
  implementations of Sequence::GranthamWeights2 and Sequence::GranthamWeights3 for an example
  of implementing weighting schemes.
  @author Kevin Thornton
  @short Deal with codons differing at 2 positions
*/
namespace Sequence
{
  class RedundancyCom95;
  class TwoSubs
  {
  private:
    struct TwoSubsImpl;
    std::unique_ptr<TwoSubsImpl> impl;
  public:
    explicit TwoSubs(void);
    void operator() (const RedundancyCom95 & sitesObj,
		     const std::string &cod1, const std::string &cod2,
		     const Sequence::WeightingScheme2 *weights2);
    ~TwoSubs (void);
    double P0 (void) const;
    double P2S (void) const;
    double P2V (void) const;
    double P4 (void) const;
    double Q0 (void) const;
    double Q2S (void) const;
    double Q2V (void) const;
    double Q4 (void) const;
  };
}
#endif
