#include <iostream>
#include <fstream>
#include <vector>
#include "TChain.h"
#include "TFile.h"
#include "TH1D.h"
#include "TH2D.h"
#include "TCanvas.h"
#include "TVector2.h"
#include "TVector3.h"
#include "TLorentzVector.h"
#include "TEfficiency.h"
#include "TLegend.h"

void ATLASLabel(Double_t x,Double_t y,Color_t color, double delx,double dely, double size=0.05)
{
    TLatex l; //l.SetTextAlign(12); l.SetTextSize(tsize);
    l.SetNDC();
    l.SetTextFont(72);
    l.SetTextColor(color);
    l.SetTextSize(size);
    //delx = 0.115*696*gPad->GetWh()/(472*gPad->GetWw());
    //delx=0.12;
    l.DrawLatex(x,y,"ATLAS");
    TLatex p;
    p.SetNDC();
    p.SetTextFont(42);
    p.SetTextColor(color);
    p.SetTextSize(size);
    p.DrawLatex(x+delx,y,"Work In Progress");
    //    p.DrawLatex(x,y,"#sqrt{s}=900GeV");
    TLatex d;
    d.SetNDC();
    d.SetTextFont(42);
    d.SetTextColor(color);
    d.SetTextSize(size);
    d.DrawLatex(x, y-dely, "Data 2022, #sqrt{s}=13.6TeV");
}

void eff(){

    gROOT->SetStyle("ATLAS");

    TFile *file = new TFile("img0829/hist0829_mu10L2mt.root");

    TH1D *pair_mass_hist = (TH1D*)file->Get("pair_mass_hist");
    TH1D *pair_deltaR_hist = (TH1D*)file->Get("pair_deltaR_hist");
    TH1D *pair_deltaPhi_hist = (TH1D*)file->Get("pair_deltaPhi_hist");
    TH1D *pair_pt_hist = (TH1D*)file->Get("pair_pt_hist");
    TH1D *cut_pair_mass_hist = (TH1D*)file->Get("cut_pair_mass_hist");
    TH1D *cut_pair_deltaR_hist = (TH1D*)file->Get("cut_pair_deltaR_hist");
    TH1D *cut_pair_deltaPhi_hist = (TH1D*)file->Get("cut_pair_deltaPhi_hist");
    TH1D *cut_pair_pt_hist = (TH1D*)file->Get("cut_pair_pt_hist");

    TH1D *singleMuonPt_hist = (TH1D*)file->Get("singleMuonPt_hist");
    TH1D *singleMuonEta_hist = (TH1D*)file->Get("singleMuonEta_hist");
    TH1D *singleMuonPhi_hist = (TH1D*)file->Get("singleMuonPhi_hist");
    TH1D *cut_singleMuonPt_hist = (TH1D*)file->Get("cut_singleMuonPt_hist");
    TH1D *cut_singleMuonEta_hist = (TH1D*)file->Get("cut_singleMuonEta_hist");
    TH1D *cut_singleMuonPhi_hist = (TH1D*)file->Get("cut_singleMuonPhi_hist");
    TH1D *min_pt_hist = (TH1D*)file->Get("min_pt_hist");
    TH1D *max_pt_hist = (TH1D*)file->Get("max_pt_hist");
    TH1D *cut_min_pt_hist = (TH1D*)file->Get("cut_min_pt_hist");
    TH1D *cut_max_pt_hist = (TH1D*)file->Get("cut_max_pt_hist");

    //cut_pair_mass_hist->SetTitle("; M_{#mu#mu}[MeV]; number of events");

    TH1D *L1_efficiency_hist = new TH1D("L1_efficiency_hist", "L1_efficiency_hist", 1000, 0, 10);

    TCanvas *c1 = new TCanvas();
    TCanvas *c2 = new TCanvas();
    TCanvas *c3 = new TCanvas();
    TCanvas *c4 = new TCanvas();
    TCanvas *c5 = new TCanvas();
    TCanvas *c6 = new TCanvas();
    TCanvas *c7 = new TCanvas();

/*
    TH1 *frame = c4->DrawFrame(0.0, 0.0, 0.3, 1.1);
    frame->GetXaxis()->SetTitle("#DeltaR_{#mu#mu}at Muonspectrometer");
    frame->GetYaxis()->SetTitle("efficiency");
*/

    // efficiency
    TEfficiency *pEff_deltaR = new TEfficiency(*cut_pair_deltaR_hist, *pair_deltaR_hist);
    pEff_deltaR->SetTitle("efficiency;deltaR at MS;efficiency");

    TEfficiency *pEff_deltaPhi = new TEfficiency(*cut_pair_deltaPhi_hist, *pair_deltaPhi_hist);
    pEff_deltaPhi->SetTitle("efficiency;deltaPhi,vertex;efficiency");


    TEfficiency *pEff_min_pt = new TEfficiency(*cut_min_pt_hist, *min_pt_hist);
    //pEff_ext_2MU10->SetTitle("2MU10 efficiency;deltaR,extrapolate;efficiency");
    //pEff_ext_2MU10->SetTitle(";#DeltaR_{#mu#mu}at Muonspectrometer;efficiency");
    pEff_min_pt->SetTitle("efficiency;pt_min mu;efficiency");
    //pEff_ext_2MU10->SetMarkerStyle(20);

    TEfficiency *pEff_max_pt = new TEfficiency(*cut_max_pt_hist, *max_pt_hist);
    pEff_max_pt->SetTitle("efficiency;pt_max mu;efficiency");

    TEfficiency *pEff_singleMuonPt = new TEfficiency(*cut_singleMuonPt_hist, *singleMuonPt_hist);
    pEff_singleMuonPt->SetTitle("efficiency;pt;efficiency");

    TEfficiency *pEff_singleMuonEta = new TEfficiency(*cut_singleMuonEta_hist, *singleMuonEta_hist);
    pEff_singleMuonEta->SetTitle("efficiency;eta;efficiency");

    TEfficiency *pEff_singleMuonPhi = new TEfficiency(*cut_singleMuonPhi_hist, *singleMuonPhi_hist);
    pEff_singleMuonPhi->SetTitle("efficiency;phi;efficiency");
    
    //pEff_ext_MU10BOM->SetTitle("BOM efficiency;deltaR,extrapolate;efficiency");
    //pEff_ext_MU10BOM->SetMarkerStyle(4);
    //pEff_ext_MU10BOM->SetMarkerColor(2);
    //pEff_ext_MU10BOM->SetLineColor(2);
/*
    TEfficiency *pEff_2MUON = new TEfficiency(*combination_hist, *probe_muon_deltaR_hist);
    pEff_2MUON->SetTitle("2MUON efficiency;deltaR,vertex;efficiency");

    TEfficiency *pEff_ext_2MUON = new TEfficiency(*ext_combination_hist, *probe_muon_ext_deltaR_hist);
    //pEff_ext_2MUON->SetTitle("2MUON efficiency;deltaR,extrapolate;efficiency");
    pEff_ext_2MUON->SetMarkerStyle(4);
    pEff_ext_2MUON->SetMarkerColor (4);
    pEff_ext_2MUON->SetLineColor (4);
*/
    /*
    TLegend *legend = new TLegend( 0.17, 0.75, 0.5, 0.85) ; //（）の中は位置の指定（左下の x , y 、右上の x , y ）
    legend->AddEntry( pEff_ext_2MU10, "(a)L1:P_{T} #geq 10GeV #times 2" , "lp") ; // AddEntry( pointer , "interpretation" , "option" )
    legend->AddEntry( pEff_ext_MU10BOM, "(b)L1:P_{T} #geq 10GeV #times 1 w/flag" , "lp") ; // option は　"f"=box, "l"="L"=line, "p"=marker
    legend->AddEntry( pEff_ext_2MUON, "(a) or (b)" , "lp") ; // option は　"f"=box, "l"="L"=line, "p"=marker
    legend->SetFillColor(0);
    legend->SetBorderSize(0);
    */

    c1->cd();
    pEff_deltaR->Draw();
    c2->cd();
    pEff_deltaPhi->Draw();
    c3->cd();
    pEff_min_pt->Draw();
    c4->cd();
    pEff_max_pt->Draw();
    c5->cd();
    pEff_singleMuonPt->Draw();
    c6->cd();
    pEff_singleMuonEta->Draw();
    c7->cd();
    pEff_singleMuonPhi->Draw();

    //ATLASLabel(0.53, 0.85, 1, 0.12, 0.05);

}