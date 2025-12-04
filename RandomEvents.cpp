#include <iostream>
#include <vector>


using namespace std;


class Random{

public:
vector<string> RandomEventDescription;
vector<int> RandomEventPath;
vector<int> MentorNumber;
vector<int> DiscoveryPointGain;


Random(){
RandomEventDescription.push_back("A critical DNA sample is contaminated");
RandomEventDescription.push_back("The main DNA sequencer machine breaks down");
RandomEventDescription.push_back("Your bioinformatics script has a bug");
RandomEventDescription.push_back("Your population model overfits! The results are meaningless");
RandomEventDescription.push_back("You spill an entire 96-well plate");
RandomEventDescription.push_back("Data storage server is full");
RandomEventDescription.push_back("Fatigue from long lab hours causes a major error");
RandomEventDescription.push_back("Your mentor points out a fundamental flaw in your method");
RandomEventDescription.push_back("Budget cuts! The lab is out of your favorite brand of pipettes");
RandomEventDescription.push_back("Failed a pop quiz from your training fellowship mentor");
RandomEventDescription.push_back("Failed an experiment due to the wrong temperature");
RandomEventDescription.push_back("Your data pipeline corrupts a batch of other files");
RandomEventDescription.push_back("Your freezer breaks overnight, ruining 50 samples");
RandomEventDescription.push_back("Your statistical analysis mistakes a lion family group for an unrelated one");
RandomEventDescription.push_back("A lion tracking collar malfunctions, you lose a month of field data");
RandomEventDescription.push_back("Struggled to understand a complex stats model in training");
RandomEventDescription.push_back("The high-performance computer is down for maintenance");
RandomEventDescription.push_back("Misread and label and sequences the wrong lion's DNA");
RandomEventDescription.push_back("Your analysis of a lion's lineage is proven incorrect by new field data");
RandomEventDescription.push_back("A mysterious contamination shows up in your control samples");
RandomEventDescription.push_back("A tip from Dr. Bio-Script helps your script run 50% faster");
RandomEventDescription.push_back("You discover an overlooked, archived tissue sample from a key lion");
RandomEventDescription.push_back("A senior scientist praises your lab notes");
RandomEventDescription.push_back("Your risky direct assignments pays off with surprisingly clean results");
RandomEventDescription.push_back("You help a co-worker debug their sequence alignment code");
RandomEventDescription.push_back("A breakthrough! Your new script works on the first try");
RandomEventDescription.push_back("Your analysis correctly identifies the two most inbred lions in the population");
RandomEventDescription.push_back("An anonymous donor, impressed by the lion project, funds new sequencers");
RandomEventDescription.push_back("You find an extra box of a rare, expensive enzyme");
RandomEventDescription.push_back("The lion conservation team sends a thank you card for your data");
RandomEventDescription.push_back("Sequencing run has an incredibly high quality score");
RandomEventDescription.push_back("You finally master Dr. Aliquot's difficult DNA extraction protocol");
RandomEventDescription.push_back("A new sample works perfectly for sequencing");
RandomEventDescription.push_back("A co-workers shares a bioinformatics script that saves you a day of work");
RandomEventDescription.push_back("You identify a rare DNA sequence in the lion population");
RandomEventDescription.push_back("A sales rep leaves a box of free pipettes");
RandomEventDescription.push_back("Dr. Loci is impressed by your deep understanding of the new sequencer's manual");
RandomEventDescription.push_back("Dr. Aliquot's protocol tip doubles your DNA yield");
RandomEventDescription.push_back("Use Dr. Bio-Script's C++ trick to automate a boring data-entry task");
RandomEventDescription.push_back("Found a calculation error in the lion's genomic database, saving a future analysis");
RandomEventDescription.push_back("Your data gets added to the main lion conservation database");
RandomEventDescription.push_back("Your data is used to successfully reunite a lost lion cub with its pride");
RandomEventDescription.push_back("Lab-wide pizza party!");
RandomEventDescription.push_back("Used Dr. Assembler's workflow to process a whole batch in one afternoon");
RandomEventDescription.push_back("You noticed a pattern in the junk DNA");
RandomEventDescription.push_back("Your analysis confirms that presence of a new gene variant");
RandomEventDescription.push_back("The machine you need is available when you need it");
RandomEventDescription.push_back("Your lab received new equipment");



RandomEventPath.push_back(1);
RandomEventPath.push_back(0);
RandomEventPath.push_back(1);
RandomEventPath.push_back(0);
RandomEventPath.push_back(1);
RandomEventPath.push_back(0);
RandomEventPath.push_back(1);
RandomEventPath.push_back(0);
RandomEventPath.push_back(1);
RandomEventPath.push_back(0);
RandomEventPath.push_back(1);
RandomEventPath.push_back(0);
RandomEventPath.push_back(1);
RandomEventPath.push_back(0);
RandomEventPath.push_back(1);
RandomEventPath.push_back(0);
RandomEventPath.push_back(1);
RandomEventPath.push_back(0);
RandomEventPath.push_back(1);
RandomEventPath.push_back(0);
RandomEventPath.push_back(1);
RandomEventPath.push_back(0);
RandomEventPath.push_back(1);
RandomEventPath.push_back(0);
RandomEventPath.push_back(1);
RandomEventPath.push_back(0);
RandomEventPath.push_back(1);
RandomEventPath.push_back(0);
RandomEventPath.push_back(1);
RandomEventPath.push_back(0);
RandomEventPath.push_back(1);
RandomEventPath.push_back(0);
RandomEventPath.push_back(1);
RandomEventPath.push_back(0);
RandomEventPath.push_back(1);
RandomEventPath.push_back(0);
RandomEventPath.push_back(1);
RandomEventPath.push_back(0);
RandomEventPath.push_back(1);
RandomEventPath.push_back(0);
RandomEventPath.push_back(1);
RandomEventPath.push_back(1);
RandomEventPath.push_back(0);
RandomEventPath.push_back(1);
RandomEventPath.push_back(0);
RandomEventPath.push_back(1);
RandomEventPath.push_back(0);
RandomEventPath.push_back(1);


MentorNumber.push_back(1);
MentorNumber.push_back(2);
MentorNumber.push_back(4);
MentorNumber.push_back(3);
MentorNumber.push_back(1);
MentorNumber.push_back(2);
MentorNumber.push_back(5);
MentorNumber.push_back(2);
MentorNumber.push_back(0);
MentorNumber.push_back(5);
MentorNumber.push_back(1);
MentorNumber.push_back(4);
MentorNumber.push_back(2);
MentorNumber.push_back(3);
MentorNumber.push_back(0);
MentorNumber.push_back(5);
MentorNumber.push_back(2);
MentorNumber.push_back(4);
MentorNumber.push_back(3);
MentorNumber.push_back(1);
MentorNumber.push_back(0);
MentorNumber.push_back(0);
MentorNumber.push_back(0);
MentorNumber.push_back(0);
MentorNumber.push_back(0);
MentorNumber.push_back(0);
MentorNumber.push_back(0);
MentorNumber.push_back(0);
MentorNumber.push_back(0);
MentorNumber.push_back(0);
MentorNumber.push_back(0);
MentorNumber.push_back(0);
MentorNumber.push_back(0);
MentorNumber.push_back(0);
MentorNumber.push_back(0);
MentorNumber.push_back(0);
MentorNumber.push_back(0);
MentorNumber.push_back(0);
MentorNumber.push_back(0);
MentorNumber.push_back(0);
MentorNumber.push_back(0);
MentorNumber.push_back(0);
MentorNumber.push_back(0);
MentorNumber.push_back(0);
MentorNumber.push_back(0);
MentorNumber.push_back(0);
MentorNumber.push_back(0);
MentorNumber.push_back(0);

DiscoveryPointGain.push_back(-500);
DiscoveryPointGain.push_back(-200);
DiscoveryPointGain.push_back(-400);
DiscoveryPointGain.push_back(-700);
DiscoveryPointGain.push_back(-800);
DiscoveryPointGain.push_back(-300);
DiscoveryPointGain.push_back(-1000);
DiscoveryPointGain.push_back(-500);
DiscoveryPointGain.push_back(-300);
DiscoveryPointGain.push_back(-800);
DiscoveryPointGain.push_back(-600);
DiscoveryPointGain.push_back(-800);
DiscoveryPointGain.push_back(-400);
DiscoveryPointGain.push_back(-600);
DiscoveryPointGain.push_back(-700);
DiscoveryPointGain.push_back(-500);
DiscoveryPointGain.push_back(-300);
DiscoveryPointGain.push_back(-500);
DiscoveryPointGain.push_back(-400);
DiscoveryPointGain.push_back(-300);
DiscoveryPointGain.push_back(800);
DiscoveryPointGain.push_back(600);
DiscoveryPointGain.push_back(500);
DiscoveryPointGain.push_back(500);
DiscoveryPointGain.push_back(700);
DiscoveryPointGain.push_back(300);
DiscoveryPointGain.push_back(1000);
DiscoveryPointGain.push_back(400);
DiscoveryPointGain.push_back(500);
DiscoveryPointGain.push_back(300);
DiscoveryPointGain.push_back(400);
DiscoveryPointGain.push_back(600);
DiscoveryPointGain.push_back(500);
DiscoveryPointGain.push_back(400);
DiscoveryPointGain.push_back(500);
DiscoveryPointGain.push_back(600);
DiscoveryPointGain.push_back(600);
DiscoveryPointGain.push_back(700);
DiscoveryPointGain.push_back(500);
DiscoveryPointGain.push_back(700);
DiscoveryPointGain.push_back(200);
DiscoveryPointGain.push_back(400);
DiscoveryPointGain.push_back(300);
DiscoveryPointGain.push_back(500);
DiscoveryPointGain.push_back(800);
DiscoveryPointGain.push_back(500);
DiscoveryPointGain.push_back(600);
DiscoveryPointGain.push_back(700);
}

};



