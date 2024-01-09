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

void overWrite_eachCut(){

    gROOT->SetStyle("ATLAS");

    // dimuon hist
    //TFile *file = new TFile("img0911/2mu10_v2.root");
    //TFile *file = new TFile("img0913/hist0913_dimuon.root");
    TFile *file = new TFile("img0915/hist0915_dimuon.root");
    //TFile *file = new TFile("img0913/hist0913_dimuon_MC.root");

    TH1D *dimuon_mass_hist = (TH1D*)file->Get("dimuon_mass_hist");
    dimuon_mass_hist->SetLineColor(2);
    TH1D *dimuon_deltaR_hist = (TH1D*)file->Get("dimuon_deltaR_hist");
    dimuon_deltaR_hist->SetLineColor(2);
    TH1D *dimuon_deltaPhi_hist = (TH1D*)file->Get("dimuon_deltaPhi_hist");
    dimuon_deltaPhi_hist->SetLineColor(2);
    TH1D *dimuon_pt_hist = (TH1D*)file->Get("dimuon_pt_hist");
    dimuon_pt_hist->SetLineColor(2);

    TH1D *dimuon_mass_barrel_hist = (TH1D*)file->Get("dimuon_mass_barrel_hist");
    dimuon_mass_barrel_hist->SetLineColor(2);
    TH1D *dimuon_deltaR_barrel_hist = (TH1D*)file->Get("dimuon_deltaR_barrel_hist");
    dimuon_deltaR_barrel_hist->SetLineColor(2);
    TH1D *dimuon_deltaPhi_barrel_hist = (TH1D*)file->Get("dimuon_deltaPhi_hist");
    dimuon_deltaPhi_barrel_hist->SetLineColor(2);
    TH1D *dimuon_pt_barrel_hist = (TH1D*)file->Get("dimuon_pt_barrel_hist");
    dimuon_pt_barrel_hist->SetLineColor(2);

    TH1D *dimuon_mass_mu10_hist = (TH1D*)file->Get("dimuon_mass_mu10_hist");
    dimuon_mass_mu10_hist->SetLineColor(3);
    TH1D *dimuon_deltaR_mu10_hist = (TH1D*)file->Get("dimuon_deltaR_mu10_hist");
    dimuon_deltaR_mu10_hist->SetLineColor(3);
    TH1D *dimuon_deltaPhi_mu10_hist = (TH1D*)file->Get("dimuon_deltaPhi_mu10_hist");
    dimuon_deltaPhi_mu10_hist->SetLineColor(3);
    TH1D *dimuon_pt_mu10_hist = (TH1D*)file->Get("dimuon_pt_mu10_hist");
    dimuon_pt_mu10_hist->SetLineColor(3);

    TH1D *dimuon_mass_2mu10_hist = (TH1D*)file->Get("dimuon_mass_2mu10_hist");
    dimuon_mass_2mu10_hist->SetLineColor(4);
    TH1D *dimuon_deltaR_2mu10_hist = (TH1D*)file->Get("dimuon_deltaR_2mu10_hist");
    dimuon_deltaR_2mu10_hist->SetLineColor(4);
    TH1D *dimuon_deltaPhi_2mu10_hist = (TH1D*)file->Get("dimuon_deltaPhi_2mu10_hist");
    dimuon_deltaPhi_2mu10_hist->SetLineColor(4);
    TH1D *dimuon_pt_2mu10_hist = (TH1D*)file->Get("dimuon_pt_2mu10_hist");
    dimuon_pt_2mu10_hist->SetLineColor(4);

    TH1D *dimuon_mass_offline2mu10_mu10L2mt_hist = (TH1D*)file->Get("dimuon_mass_offline2mu10_mu10L2mt_hist");
    dimuon_mass_offline2mu10_mu10L2mt_hist->SetLineColor(6);
    TH1D *dimuon_deltaR_offline2mu10_mu10L2mt_hist = (TH1D*)file->Get("dimuon_deltaR_offline2mu10_mu10L2mt_hist");
    dimuon_deltaR_offline2mu10_mu10L2mt_hist->SetLineColor(6);
    TH1D *dimuon_deltaPhi_offline2mu10_mu10L2mt_hist = (TH1D*)file->Get("dimuon_deltaPhi_offline2mu10_mu10L2mt_hist");
    dimuon_deltaPhi_offline2mu10_mu10L2mt_hist->SetLineColor(6);
    TH1D *dimuon_pt_offline2mu10_mu10L2mt_hist = (TH1D*)file->Get("dimuon_pt_offline2mu10_mu10L2mt_hist");
    dimuon_pt_offline2mu10_mu10L2mt_hist->SetLineColor(6);

    TH1D *dimuon_mass_offline2mu10_2mu10L2mt_hist = (TH1D*)file->Get("dimuon_mass_offline2mu10_2mu10L2mt_hist");
    dimuon_mass_offline2mu10_2mu10L2mt_hist->SetLineColor(7);
    TH1D *dimuon_deltaR_offline2mu10_2mu10L2mt_hist = (TH1D*)file->Get("dimuon_deltaR_offline2mu10_2mu10L2mt_hist");
    dimuon_deltaR_offline2mu10_2mu10L2mt_hist->SetLineColor(7);
    TH1D *dimuon_deltaPhi_offline2mu10_2mu10L2mt_hist = (TH1D*)file->Get("dimuon_deltaPhi_offline2mu10_2mu10L2mt_hist");
    dimuon_deltaPhi_offline2mu10_2mu10L2mt_hist->SetLineColor(7);
    TH1D *dimuon_pt_offline2mu10_2mu10L2mt_hist = (TH1D*)file->Get("dimuon_pt_offline2mu10_2mu10L2mt_hist");
    dimuon_pt_offline2mu10_2mu10L2mt_hist->SetLineColor(7);
/*
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
    TH1D *cut_pair_ext_deltaR_hist = (TH1D*)file->Get("cut_pair_ext_deltaR_hist");
    cut_pair_ext_deltaR_hist->SetLineColor(2);
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
*/
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

    /*
    TLegend *legend = new TLegend( 0.17, 0.75, 0.5, 0.85) ; //（）の中は位置の指定（左下の x , y 、右上の x , y ）
    legend->AddEntry( pEff_ext_2MU10, "(a)L1:P_{T} #geq 10GeV #times 2" , "lp") ; // AddEntry( pointer , "interpretation" , "option" )
    legend->AddEntry( pEff_ext_MU10BOM, "(b)L1:P_{T} #geq 10GeV #times 1 w/flag" , "lp") ; // option は　"f"=box, "l"="L"=line, "p"=marker
    legend->AddEntry( pEff_ext_2MUON, "(a) or (b)" , "lp") ; // option は　"f"=box, "l"="L"=line, "p"=marker
    legend->SetFillColor(0);
    legend->SetBorderSize(0);
    */
/*
    TLegend *legend1 = new TLegend( 0.57, 0.75, 0.9, 0.85) ; //（）の中は位置の指定（左下の x , y 、右上の x , y ）
    legend1->AddEntry( cut_pair_deltaR_hist, "(a)w/o J/psi mass cut" , "lp") ; // AddEntry( pointer , "interpretation" , "option" )
    legend1->AddEntry( cut_pair_deltaR_Jpsi_hist, "(b)w/ J/psi mass cut" , "lp") ; // option は　"f"=box, "l"="L"=line, "p"=marker
    //legend1->AddEntry( pEff_ext_2MUON, "(a) or (b)" , "lp") ; // option は　"f"=box, "l"="L"=line, "p"=marker
    legend1->SetFillColor(0);
    legend1->SetBorderSize(0);
*/
/*
    TLegend *legend2 = new TLegend( 0.17, 0.75, 0.5, 0.85) ; //（）の中は位置の指定（左下の x , y 、右上の x , y ）
    legend2->AddEntry( pEff_deltaR_MS_Jpsi, "(a)data" , "lp") ; // AddEntry( pointer , "interpretation" , "option" )
    legend2->AddEntry( pEff_deltaR_MS_Jpsi_MC, "(b)MC" , "lp") ; // option は　"f"=box, "l"="L"=line, "p"=marker
    //legend2->AddEntry( pEff_ext_2MUON, "(a) or (b)" , "lp") ; // option は　"f"=box, "l"="L"=line, "p"=marker
    legend2->SetFillColor(0);
    legend2->SetBorderSize(0);
*/

    TCanvas *c1 = new TCanvas();
    //TH1 *frame1 = c1->DrawFrame(0.0, 0.0, 10, 4000000);
    
    //MC
    //TH1 *frame1 = c1->DrawFrame(0.0, 0.0, 10, 13000);
    //data
    //TH1 *frame1 = c1->DrawFrame(0.0, 0.0, 10, 500);
    TH1 *frame1 = c1->DrawFrame(0.0, 0.0, 10, 500000);
    frame1->GetXaxis()->SetTitle("dimuon mass");
    frame1->GetYaxis()->SetTitle("number of entries");
    dimuon_mass_hist->Draw("same");
    //dimuon_mass_barrel_hist->Draw("same");
    dimuon_mass_mu10_hist->Draw("same");
    dimuon_mass_2mu10_hist->Draw("same");
    dimuon_mass_offline2mu10_mu10L2mt_hist->Draw("same");
    dimuon_mass_offline2mu10_2mu10L2mt_hist->Draw("same");
    //legend1->Draw("same");

    TCanvas *c2 = new TCanvas();
    //TH1 *frame2 = c2->DrawFrame(0.0, 0.0, 1.0, 1500000);
    
    //MC
    //TH1 *frame2 = c2->DrawFrame(0.0, 0.0, 1.0, 10000);
    //data
    //TH1 *frame2 = c2->DrawFrame(0.0, 0.0, 1.0, 2000);
    TH1 *frame2 = c2->DrawFrame(0.0, 0.0, 1.0, 700000);
    frame2->GetXaxis()->SetTitle("#DeltaR_{#mu#mu}at vertex");
    frame2->GetYaxis()->SetTitle("number of entries");
    dimuon_deltaR_hist->Draw("same");
    //dimuon_deltaR_barrel_hist->Draw("same");
    dimuon_deltaR_mu10_hist->Draw("same");
    dimuon_deltaR_2mu10_hist->Draw("same");
    dimuon_deltaR_offline2mu10_mu10L2mt_hist->Draw("same");
    dimuon_deltaR_offline2mu10_2mu10L2mt_hist->Draw("same");

    TCanvas *c3 = new TCanvas();
    //TH1 *frame3 = c3->DrawFrame(-1, 0.0, 1, 1500000);

    //MC
    //TH1 *frame3 = c3->DrawFrame(-1, 0.0, 1, 10000);

    //data
    //TH1 *frame3 = c3->DrawFrame(-1, 0.0, 1, 3000);
    TH1 *frame3 = c3->DrawFrame(-1, 0.0, 1, 1700000);
    frame3->GetXaxis()->SetTitle("#DeltaPhi_{#mu#mu}at vertex");
    frame3->GetYaxis()->SetTitle("number of entries");
    dimuon_deltaPhi_hist->Draw("same");
    //dimuon_deltaPhi_barrel_hist->Draw("same");
    dimuon_deltaPhi_mu10_hist->Draw("same");
    dimuon_deltaPhi_2mu10_hist->Draw("same");
    dimuon_deltaPhi_offline2mu10_mu10L2mt_hist->Draw("same");
    dimuon_deltaPhi_offline2mu10_2mu10L2mt_hist->Draw("same");

    TCanvas *c4 = new TCanvas();
    //TH1 *frame4 = c4->DrawFrame(0.0, 0.0, 100, 6000000);

    //MC
    //TH1 *frame4 = c4->DrawFrame(0.0, 0.0, 100, 20000);
    //data
    //TH1 *frame4 = c4->DrawFrame(0.0, 0.0, 100, 4000);
    TH1 *frame4 = c4->DrawFrame(0.0, 0.0, 100, 4000000);
    frame4->GetXaxis()->SetTitle("p_{T}");
    frame4->GetYaxis()->SetTitle("number of entries");
    dimuon_pt_hist->Draw("same");
    //dimuon_pt_barrel_hist->Draw("same");
    dimuon_pt_mu10_hist->Draw("same");
    dimuon_pt_2mu10_hist->Draw("same");
    dimuon_pt_offline2mu10_mu10L2mt_hist->Draw("same");
    dimuon_pt_offline2mu10_2mu10L2mt_hist->Draw("same");
/*
    TCanvas *c5 = new TCanvas();
    TH1 *frame5 = c5->DrawFrame(0.0, 0.0, 0.5, 800);
    frame5->GetXaxis()->SetTitle("#DeltaR_{#mu#mu}at Muonspectrometer");
    frame5->GetYaxis()->SetTitle("number of entries");
    pair_ext_deltaR_hist->Draw("same");
    pair_ext_deltaR_Jpsi_hist->Draw("same");

    TCanvas *c6 = new TCanvas();
    TH1 *frame6 = c6->DrawFrame(0.0, 0.0, 100, 7200);
    frame6->GetXaxis()->SetTitle("offline muon p_{T}");
    frame6->GetYaxis()->SetTitle("number of entries");
    pair_pt_hist->Draw("same");
    pair_pt_Jpsi_hist->Draw("same");
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