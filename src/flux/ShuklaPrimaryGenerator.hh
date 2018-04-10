//******************************************************************************
// PrimaryGeneratorAction.hh
//
// This class is a class derived from G4VUserPrimaryGeneratorAction for
// constructing the process used to generate incident particles.
//
// 1.00 JMV, LLNL, JAN-2007:  First version.
//******************************************************************************
//
#ifndef __ShuklaPrimaryGenerator_H__
#define __ShuklaPrimaryGenerator_H__

#include "TF1.h"
#include <G4Box.hh>

#include "G4VUserPrimaryGeneratorAction.hh"

// #include "PrimaryGeneratorMessenger.hh"

#include "G4ThreeVector.hh"
#include "G4DataVector.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleGun.hh"
#include "Randomize.hh"
#include "globals.hh"
#include "CRYSetup.h"
#include "CRYGenerator.h"
#include "CRYParticle.h"
#include "CRYUtils.h"
#include "vector"
// #include "RNGWrapper.hh"
#include "G4Types.hh"

#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4ParticleGun.hh"
#include "globals.hh"
#include "db/DBLink.hh"
#include "geo/GeoBox.hh"

#include "G4Event.hh"

#include "G4SystemOfUnits.hh"
#include "G4RunManager.hh"

#include "TF1.h"
#include "TMath.h"
#include <G4Box.hh>
#include <cmath>
#include <iomanip>

namespace COSMIC {
namespace { G4Mutex myMutex = G4MUTEX_INITIALIZER; }

class ShuklaPrimaryGenerator : public G4VUserPrimaryGeneratorAction
{
public:
    ShuklaPrimaryGenerator();
    ~ShuklaPrimaryGenerator();

    void SampleParticleType();
    G4ThreeVector SampleDirection();
    void GeneratePrimaries(G4Event* anEvent);

    G4Box* GetSourceBox();
    std::vector<G4Box*> GetTargetBoxes();
    std::vector<G4ThreeVector> GetTargetBoxPositions();

private:

    DBLink* fTable;

    G4double fMinEnergy;
    G4double fMaxEnergy;

    TF1 *fEnergyPDF;
    TF1 *fZenithPDF;

    G4double fFluxIntegrated;

    G4double fPar_I0; 
    G4double fPar_n; 
    G4double fPar_E0; 
    G4double fPar_eps; 
    G4double fPar_rad;
    G4double fPar_dis;

    std::vector<G4ParticleDefinition*> fParticleDefs;
    G4ParticleGun* fParticleGun;

    G4Box* fSourceBox;
    std::vector<G4Box*> fTargetBoxes;
    std::vector<G4ThreeVector> fTargetBoxPositions;

    std::string fSourceBoxIndex;
    bool fCheckTargetBoxes;

    G4ThreeVector fSourceBoxPosition;




};

} // - namespace COSMIC

#endif