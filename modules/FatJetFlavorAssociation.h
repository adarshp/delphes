/*
 *  Delphes: a framework for fast simulation of a generic collider experiment
 *  Copyright (C) 2012-2014  Universite catholique de Louvain (UCL), Belgium
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef FatJetFlavorAssociation_h
#define FatJetFlavorAssociation_h

/** \class FatJetFlavorAssociation
 *
 *  Find origin of jet and evaluate jet flavor
 *
 *  \author P. Demin - UCL, Louvain-la-Neuve
 *
 */

#include "classes/DelphesModule.h"
#include "classes/DelphesClasses.h"
#include <map>

//test
    #include <string>
//test

class TObjArray;
class DelphesFormula;

class ExRootFilter;
class PartonClassifierFat;
class ParticleLHEFClassifierFat;

class FatJetFlavorAssociation: public DelphesModule
{
public:

  FatJetFlavorAssociation();
  ~FatJetFlavorAssociation();

  void Init();
  void Process();
  void Finish();

  void GetAlgoFlavor(Candidate *jet, TObjArray *partonArray, TObjArray *partonLHEFArray);
  void GetPhysicsFlavor(Candidate *jet, TObjArray *partonArray, TObjArray *partonLHEFArray);

private:

  Double_t fDeltaR;
    
    //test
    std::string myname;
    //test

  PartonClassifierFat *fPartonClassifierFat; //!
  ParticleLHEFClassifierFat *fParticleLHEFClassifierFat; //!

  ExRootFilter *fPartonFilter;
  ExRootFilter *fParticleLHEFFilter;

  TIterator *fItPartonInputArray; //!
  TIterator *fItParticleInputArray; //!
  TIterator *fItParticleLHEFInputArray; //!
  TIterator *fItJetInputArray; //!

  const TObjArray *fPartonInputArray; //!
  const TObjArray *fParticleInputArray; //!
  const TObjArray *fParticleLHEFInputArray; //!
  const TObjArray *fJetInputArray; //!

  ClassDef(FatJetFlavorAssociation, 1)
};

#endif
