#include "mnemonica.h"

namespace spacer {

static QuestionSet const mnemonica_questions{
    {"MNE01", "1", "4C"},  {"MNE02", "2", "2H"},  {"MNE03", "3", "7D"},
    {"MNE04", "4", "3C"},  {"MNE05", "5", "4H"},  {"MNE06", "6", "6D"},
    {"MNE07", "7", "AS"},  {"MNE08", "8", "5H"},  {"MNE09", "9", "9S"},
    {"MNE10", "10", "2S"}, {"MNE11", "11", "QH"}, {"MNE12", "12", "3D"},
    {"MNE13", "13", "QC"}, {"MNE14", "14", "8H"}, {"MNE15", "15", "6S"},
    {"MNE16", "16", "5S"}, {"MNE17", "17", "9H"}, {"MNE18", "18", "KC"},
    {"MNE19", "19", "2D"}, {"MNE20", "20", "JH"}, {"MNE21", "21", "3S"},
    {"MNE22", "22", "8S"}, {"MNE23", "23", "6H"}, {"MNE24", "24", "TC"},
    {"MNE25", "25", "5D"}, {"MNE26", "26", "KD"}, {"MNE27", "27", "2C"},
    {"MNE28", "28", "3H"}, {"MNE29", "29", "8D"}, {"MNE30", "30", "5C"},
    {"MNE31", "31", "KS"}, {"MNE32", "32", "JD"}, {"MNE33", "33", "8C"},
    {"MNE34", "34", "TS"}, {"MNE35", "35", "KH"}, {"MNE36", "36", "JC"},
    {"MNE37", "37", "7S"}, {"MNE38", "38", "TH"}, {"MNE39", "39", "AD"},
    {"MNE40", "40", "4S"}, {"MNE41", "41", "7H"}, {"MNE42", "42", "4D"},
    {"MNE43", "43", "AC"}, {"MNE44", "44", "9C"}, {"MNE45", "45", "JS"},
    {"MNE46", "46", "QD"}, {"MNE47", "47", "7C"}, {"MNE48", "48", "QS"},
    {"MNE49", "49", "TD"}, {"MNE50", "50", "6C"}, {"MNE51", "51", "AH"},
    {"MNE52", "52", "9D"}};

QuestionSet mnemonica() { return QuestionSet(mnemonica_questions); }

}  // namespace spacer
