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
    d.DrawLatex(x, y-dely, "Data 2023, #sqrt{s}=13.6TeV");
}

void overWrite(){

    gROOT->SetStyle("ATLAS");

    //TFile *file = new TFile("img0911/hist0911_v5.root");
    //TFile *file = new TFile("img0913/hist0911_2mu10.root");
    TFile *file = new TFile("img0915/hist0915_2mu10_withL2mtmatch_v2.root");
    //TFile *file = new TFile("img0911/hist0911_2mu10_noPtEtaCut.root");

    TH1D *pair_mass_hist = (TH1D*)file->Get("pair_mass_hist");
    pair_mass_hist->SetLineColor(2);
    TH1D *pair_deltaR_hist = (TH1D*)file->Get("pair_deltaR_hist");
    pair_deltaR_hist->SetLineColor(2);
    TH1D *pair_ext_deltaR_hist = (TH1D*)file->Get("pair_ext_deltaR_hist");
    pair_ext_deltaR_hist->SetLineColor(2);
    TH1D *pair_deltaPhi_hist = (TH1D*)file->Get("pair_deltaPhi_hist");
    pair_deltaPhi_hist->SetLineColor(2);
    TH1D *pair_pt_hist = (TH1D*)file->Get("pair_pt_hist");
    pair_pt_hist->SetLineColor(2);
    TH1D *cut_pair_mass_hist = (TH1D*)file->Get("cut_pair_mass_hist");
    cut_pair_mass_hist->SetLineColor(2);
    TH1D *cut_pair_deltaR_hist = (TH1D*)file->Get("cut_pair_deltaR_hist");
    cut_pair_deltaR_hist->SetLineColor(2);
    TH1D *fine_cut_pair_ext_deltaR_hist = (TH1D*)file->Get("cut_pair_ext_deltaR_hist");
    fine_cut_pair_ext_deltaR_hist->SetLineColor(2);
    TH1D *cut_pair_deltaPhi_hist = (TH1D*)file->Get("cut_pair_deltaPhi_hist");
    cut_pair_deltaPhi_hist->SetLineColor(2);
    TH1D *cut_pair_pt_hist = (TH1D*)file->Get("cut_pair_pt_hist");
    cut_pair_pt_hist->SetLineColor(2);

    TH1D *pair_mass_Jpsi_hist = (TH1D*)file->Get("pair_mass_Jpsi_hist");
    pair_mass_Jpsi_hist->SetLineColor(4);
    TH1D *pair_deltaR_Jpsi_hist = (TH1D*)file->Get("pair_deltaR_Jpsi_hist");
    pair_deltaR_Jpsi_hist->SetLineColor(4);
    TH1D *pair_ext_deltaR_Jpsi_hist = (TH1D*)file->Get("pair_ext_deltaR_Jpsi_hist");
    pair_ext_deltaR_Jpsi_hist->SetLineColor(4);
    TH1D *pair_deltaPhi_Jpsi_hist = (TH1D*)file->Get("pair_deltaPhi_Jpsi_hist");
    pair_deltaPhi_Jpsi_hist->SetLineColor(4);
    TH1D *pair_pt_Jpsi_hist = (TH1D*)file->Get("pair_pt_Jpsi_hist");
    pair_pt_Jpsi_hist->SetLineColor(4);
    TH1D *cut_pair_mass_Jpsi_hist = (TH1D*)file->Get("cut_pair_mass_Jpsi_hist");
    cut_pair_mass_Jpsi_hist->SetLineColor(4);
    TH1D *cut_pair_deltaR_Jpsi_hist = (TH1D*)file->Get("cut_pair_deltaR_Jpsi_hist");
    cut_pair_deltaR_Jpsi_hist->SetLineColor(4);
    TH1D *cut_pair_ext_deltaR_Jpsi_hist = (TH1D*)file->Get("cut_pair_ext_deltaR_Jpsi_hist");
    cut_pair_ext_deltaR_Jpsi_hist->SetLineColor(4);
    TH1D *cut_pair_deltaPhi_Jpsi_hist = (TH1D*)file->Get("cut_pair_deltaPhi_Jpsi_hist");
    cut_pair_deltaPhi_Jpsi_hist->SetLineColor(4);
    TH1D *cut_pair_pt_Jpsi_hist = (TH1D*)file->Get("cut_pair_pt_Jpsi_hist");
    cut_pair_pt_Jpsi_hist->SetLineColor(4);

    TH1D *eff_pair_mass_hist = (TH1D*)file->Get("eff_pair_mass_hist");
    TH1D *eff_cut_pair_mass_hist = (TH1D*)file->Get("eff_cut_pair_mass_hist");
    TH1D *eff_pair_mass_Jpsi_hist = (TH1D*)file->Get("eff_pair_mass_Jpsi_hist");
    TH1D *eff_cut_pair_mass_Jpsi_hist = (TH1D*)file->Get("eff_cut_pair_mass_Jpsi_hist");

    TH1D *mu1_pt_hist = (TH1D*)file->Get("mu1_pt_hist");
    mu1_pt_hist->SetLineColor(4);
    TH1D *mu1_eta_hist = (TH1D*)file->Get("mu1_eta_hist");
    mu1_eta_hist->SetLineColor(4);
    TH1D *ptcut_mu1_pt_hist = (TH1D*)file->Get("ptcut_mu1_pt_hist");
    ptcut_mu1_pt_hist->SetLineColor(2);
    TH1D *etacut_mu1_eta_hist = (TH1D*)file->Get("etacut_mu1_eta_hist");
    etacut_mu1_eta_hist->SetLineColor(2);

    TH1D *mu2_pt_hist = (TH1D*)file->Get("mu2_pt_hist");
    mu2_pt_hist->SetLineColor(4);
    TH1D *mu2_eta_hist = (TH1D*)file->Get("mu2_eta_hist");
    mu2_eta_hist->SetLineColor(4);
    TH1D *ptcut_mu2_pt_hist = (TH1D*)file->Get("ptcut_mu2_pt_hist");
    ptcut_mu2_pt_hist->SetLineColor(2);
    TH1D *etacut_mu2_eta_hist = (TH1D*)file->Get("etacut_mu2_eta_hist");
    etacut_mu2_eta_hist->SetLineColor(2);

/*
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
*/
    //TH1D *dimuon_mass_hist = (TH1D*)file1->Get("dimuon_mass_hist");
    //cut_pair_mass_hist->SetTitle("; M_{#mu#mu}[MeV]; number of events");

    TH1D *L1_efficiency_hist = new TH1D("L1_efficiency_hist", "L1_efficiency_hist", 1000, 0, 10);

    /*
    TLegend *legend = new TLegend( 0.17, 0.75, 0.5, 0.85) ; //（）の中は位置の指定（左下の x , y 、右上の x , y ）
    legend->AddEntry( pEff_ext_2MU10, "(a)L1:P_{T} #geq 10GeV #times 2" , "lp") ; // AddEntry( pointer , "interpretation" , "option" )
    legend->AddEntry( pEff_ext_MU10BOM, "(b)L1:P_{T} #geq 10GeV #times 1 w/flag" , "lp") ; // option は　"f"=box, "l"="L"=line, "p"=marker
    legend->AddEntry( pEff_ext_2MUON, "(a) or (b)" , "lp") ; // option は　"f"=box, "l"="L"=line, "p"=marker
    legend->SetFillColor(0);
    legend->SetBorderSize(0);
    */

    TLegend *legend1 = new TLegend( 0.57, 0.75, 0.9, 0.85) ; //（）の中は位置の指定（左下の x , y 、右上の x , y ）
    legend1->AddEntry( cut_pair_deltaR_hist, "(a)w/o J/psi mass cut" , "lp") ; // AddEntry( pointer , "interpretation" , "option" )
    legend1->AddEntry( cut_pair_deltaR_Jpsi_hist, "(b)w/ J/psi mass cut" , "lp") ; // option は　"f"=box, "l"="L"=line, "p"=marker
    //legend1->AddEntry( pEff_ext_2MUON, "(a) or (b)" , "lp") ; // option は　"f"=box, "l"="L"=line, "p"=marker
    legend1->SetFillColor(0);
    legend1->SetBorderSize(0);

    TLegend *legend2 = new TLegend( 0.57, 0.75, 0.9, 0.85) ; //（）の中は位置の指定（左下の x , y 、右上の x , y ）
    legend2->AddEntry( mu1_pt_hist, "(a)w/o p_{T} cut" , "lp") ; // AddEntry( pointer , "interpretation" , "option" )
    legend2->AddEntry( ptcut_mu1_pt_hist, "(b)w/ p_{T} cut" , "lp") ; // option は　"f"=box, "l"="L"=line, "p"=marker
    //legend1->AddEntry( pEff_ext_2MUON, "(a) or (b)" , "lp") ; // option は　"f"=box, "l"="L"=line, "p"=marker
    legend2->SetFillColor(0);
    legend2->SetBorderSize(0);

    TLegend *legend3 = new TLegend( 0.57, 0.75, 0.9, 0.85) ; //（）の中は位置の指定（左下の x , y 、右上の x , y ）
    legend3->AddEntry( mu1_eta_hist, "(a)w/o p_{T}, barrel cut" , "lp") ; // AddEntry( pointer , "interpretation" , "option" )
    legend3->AddEntry( etacut_mu1_eta_hist, "(b)w/ p_{T, }barrel cut" , "lp") ; // option は　"f"=box, "l"="L"=line, "p"=marker
    //legend1->AddEntry( pEff_ext_2MUON, "(a) or (b)" , "lp") ; // option は　"f"=box, "l"="L"=line, "p"=marker
    legend3->SetFillColor(0);
    legend3->SetBorderSize(0);
/*
    TLegend *legend2 = new TLegend( 0.17, 0.75, 0.5, 0.85) ; //（）の中は位置の指定（左下の x , y 、右上の x , y ）
    legend2->AddEntry( pEff_deltaR_MS_Jpsi, "(a)data" , "lp") ; // AddEntry( pointer , "interpretation" , "option" )
    legend2->AddEntry( pEff_deltaR_MS_Jpsi_MC, "(b)MC" , "lp") ; // option は　"f"=box, "l"="L"=line, "p"=marker
    //legend2->AddEntry( pEff_ext_2MUON, "(a) or (b)" , "lp") ; // option は　"f"=box, "l"="L"=line, "p"=marker
    legend2->SetFillColor(0);
    legend2->SetBorderSize(0);
*/

    TCanvas *c1 = new TCanvas();
    TH1 *frame1 = c1->DrawFrame(0.0, 0.0, 0.5, 900);
    //TH1 *frame1 = c1->DrawFrame(0.0, 0.0, 0.5, 30);
    frame1->GetXaxis()->SetTitle("#DeltaR_{#mu#mu}at vertex");
    frame1->GetYaxis()->SetTitle("number of entries");
    cut_pair_deltaR_hist->Draw("same");
    cut_pair_deltaR_Jpsi_hist->Draw("same");
    legend1->Draw("same");

    TCanvas *c2 = new TCanvas();
    TH1 *frame2 = c2->DrawFrame(0.0, 0.0, 0.5, 1200);
    //TH1 *frame2 = c2->DrawFrame(0.0, 0.0, 0.5, 30);
    frame2->GetXaxis()->SetTitle("#DeltaR_{#mu#mu}at Muonspectrometer");
    frame2->GetYaxis()->SetTitle("number of entries");
    fine_cut_pair_ext_deltaR_hist->Draw("same");
    cut_pair_ext_deltaR_Jpsi_hist->Draw("same");

    TCanvas *c3 = new TCanvas();
    //TH1 *frame3 = c3->DrawFrame(0.0, 0.0, 100, 2200);
    //TH1 *frame3 = c3->DrawFrame(0.0, 0.0, 100, 30);
    //frame3->GetXaxis()->SetTitle("offline muon p_{T}");
    //frame3->GetYaxis()->SetTitle("number of entries");
    cut_pair_pt_hist->Draw("same");
    cut_pair_pt_Jpsi_hist->Draw("same");
    c3->SetLogy();

    TCanvas *c4 = new TCanvas();
    TH1 *frame4 = c4->DrawFrame(0.0, 0.0, 0.5, 1500);
    //TH1 *frame4 = c4->DrawFrame(0.0, 0.0, 0.5, 30);
    frame4->GetXaxis()->SetTitle("#DeltaR_{#mu#mu}at vertex");
    frame4->GetYaxis()->SetTitle("number of entries");
    pair_deltaR_hist->Draw("same");
    pair_deltaR_Jpsi_hist->Draw("same");

    TCanvas *c5 = new TCanvas();
    TH1 *frame5 = c5->DrawFrame(0.0, 0.0, 0.5, 1900);
    //TH1 *frame5 = c5->DrawFrame(0.0, 0.0, 0.5, 30);
    frame5->GetXaxis()->SetTitle("#DeltaR_{#mu#mu}at Muonspectrometer");
    frame5->GetYaxis()->SetTitle("number of entries");
    pair_ext_deltaR_hist->Draw("same");
    pair_ext_deltaR_Jpsi_hist->Draw("same");

    TCanvas *c6 = new TCanvas();
    //TH1 *frame6 = c6->DrawFrame(0.0, 0.0, 100, 7200);
    //TH1 *frame6 = c6->DrawFrame(0.0, 0.0, 100, 50);
    //frame6->GetXaxis()->SetTitle("offline muon p_{T}");
    //frame6->GetYaxis()->SetTitle("number of entries");
    pair_pt_hist->Draw("same");
    pair_pt_Jpsi_hist->Draw("same");
    c6->SetLogy();
/*
    TCanvas *c7 = new TCanvas();
    TH1 *frame7 = c7->DrawFrame(0.0, 0.0, 100, 30000000);
    frame7->GetXaxis()->SetTitle("p_{T}");
    frame7->GetYaxis()->SetTitle("number of entries");
    mu1_pt_hist->Draw("same");
    ptcut_mu1_pt_hist->Draw("same");
    legend2->Draw("same");

    TCanvas *c8 = new TCanvas();
    TH1 *frame8 = c8->DrawFrame(-3, 0.0, 3, 5000000);
    frame8->GetXaxis()->SetTitle("#eta");
    frame8->GetYaxis()->SetTitle("number of entries");
    mu1_eta_hist->Draw("same");
    etacut_mu1_eta_hist->Draw("same");
    legend3->Draw("same");

    TCanvas *c9 = new TCanvas();
    TH1 *frame9 = c9->DrawFrame(0.0, 0.0, 100, 4000000);
    frame9->GetXaxis()->SetTitle("p_{T}");
    frame9->GetYaxis()->SetTitle("number of entries");
    mu2_pt_hist->Draw("same");
    ptcut_mu2_pt_hist->Draw("same");

    TCanvas *c10 = new TCanvas();
    TH1 *frame10 = c10->DrawFrame(-3, 0.0, 3, 500000);
    frame10->GetXaxis()->SetTitle("#eta");
    frame10->GetYaxis()->SetTitle("number of entries");
    mu2_eta_hist->Draw("same");
    etacut_mu2_eta_hist->Draw("same");
*/
/*
    TCanvas *c4 = new TCanvas();
    TH1 *frame4 = c4->DrawFrame(0.0, 0.0, 0.5, 1);
    frame4->GetXaxis()->SetTitle("#DeltaR_{#mu#mu}at Muonspectrometer");
    frame4->GetYaxis()->SetTitle("efficiency");
    pEff_deltaR_MS_Jpsi->Draw("same");
    //pEff_deltaR_MS_Jpsi_MC->Draw("same");
    //legend2->Draw("same");

    TCanvas *c5 = new TCanvas();
    TH1 *frame5 = c5->DrawFrame(0.0, 0.0, 10, 1);
    frame5->GetXaxis()->SetTitle("imvariant mass");
    frame5->GetYaxis()->SetTitle("efficiency");
    pEff_mass->Draw("same");

    TCanvas *c6 = new TCanvas();
    TH1 *frame6 = c6->DrawFrame(0.0, 0.0, 10, 1);
    frame6->GetXaxis()->SetTitle("imvariant mass");
    frame6->GetYaxis()->SetTitle("efficiency");
    pEff_mass_Jpsi->Draw("same");
*/

    //ATLASLabel(0.53, 0.85, 1, 0.12, 0.05);

}