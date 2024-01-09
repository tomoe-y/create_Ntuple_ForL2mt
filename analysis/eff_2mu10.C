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

void eff_2mu10(){

    gROOT->SetStyle("ATLAS");

    //TFile *file = new TFile("img0829/hist0829_mu10L2mt.root");
    //TFile *file = new TFile("img0904/hist0904_mu10L2mt_2mu10.root");
    //TFile *file = new TFile("img0905/hist0905_dimuon_15.root");
    //TFile *file = new TFile("img0905/hist0905_2mu10_Jpsi.root");
    TFile *file1 = new TFile("img0906/hist0906_2mu10_MC.root");
    TFile *file2 = new TFile("img0908/hist0908_2mu10.root");
    //TFile *file = new TFile("img0902/hist0902_2mu10_Jpsi.root");
    //TFile *file = new TFile("img0902/hist0902_2mu10_MC.root");
    //TFile *file = new TFile("img0911/hist0911_2mu10.root");
    
    //TFile *file = new TFile("img0911/hist0911_v5.root");
    //TFile *file = new TFile("img0913/hist0911_2mu10.root");
    TFile *file = new TFile("img0915/hist0915_2mu10_withL2mtmatch_v2.root");
    //TFile *file = new TFile("img0911/hist0911_2mu10_noPtEtaCut.root");
    //TFile *file = new TFile("img0911/2mu10_v2.root");


    TH1D *pair_mass_hist = (TH1D*)file->Get("pair_mass_hist");
    TH1D *pair_deltaR_hist = (TH1D*)file->Get("pair_deltaR_hist");
    TH1D *pair_ext_deltaR_hist = (TH1D*)file->Get("pair_ext_deltaR_hist");
    TH1D *pair_deltaPhi_hist = (TH1D*)file->Get("pair_deltaPhi_hist");
    TH1D *pair_pt_hist = (TH1D*)file->Get("pair_pt_hist");
    TH1D *cut_pair_mass_hist = (TH1D*)file->Get("cut_pair_mass_hist");
    TH1D *cut_pair_deltaR_hist = (TH1D*)file->Get("cut_pair_deltaR_hist");
    TH1D *fine_cut_pair_ext_deltaR_hist = (TH1D*)file->Get("cut_pair_ext_deltaR_hist");
    TH1D *cut_pair_deltaPhi_hist = (TH1D*)file->Get("cut_pair_deltaPhi_hist");
    TH1D *cut_pair_pt_hist = (TH1D*)file->Get("cut_pair_pt_hist");

    TH1D *pair_mass_Jpsi_hist = (TH1D*)file->Get("pair_mass_Jpsi_hist");

    //TH1D *pair_deltaR_Jpsi_hist_MC = (TH1D*)file1->Get("pair_deltaR_Jpsi_hist");
    //TH1D *pair_ext_deltaR_Jpsi_hist_MC = (TH1D*)file1->Get("pair_ext_deltaR_Jpsi_hist");
    TH1D *pair_deltaR_Jpsi_hist = (TH1D*)file->Get("pair_deltaR_Jpsi_hist");
    TH1D *pair_ext_deltaR_Jpsi_hist = (TH1D*)file->Get("pair_ext_deltaR_Jpsi_hist");

    TH1D *pair_deltaPhi_Jpsi_hist = (TH1D*)file->Get("pair_deltaPhi_Jpsi_hist");
    TH1D *pair_pt_Jpsi_hist = (TH1D*)file->Get("pair_pt_Jpsi_hist");
    TH1D *cut_pair_mass_Jpsi_hist = (TH1D*)file->Get("cut_pair_mass_Jpsi_hist");

    //TH1D *cut_pair_deltaR_Jpsi_hist_MC = (TH1D*)file1->Get("cut_pair_deltaR_Jpsi_hist");
    //TH1D *cut_pair_ext_deltaR_Jpsi_hist_MC = (TH1D*)file1->Get("cut_pair_ext_deltaR_Jpsi_hist");
    TH1D *cut_pair_deltaR_Jpsi_hist = (TH1D*)file->Get("cut_pair_deltaR_Jpsi_hist");
    TH1D *cut_pair_ext_deltaR_Jpsi_hist = (TH1D*)file->Get("cut_pair_ext_deltaR_Jpsi_hist");

    TH1D *cut_pair_deltaPhi_Jpsi_hist = (TH1D*)file->Get("cut_pair_deltaPhi_Jpsi_hist");
    TH1D *cut_pair_pt_Jpsi_hist = (TH1D*)file->Get("cut_pair_pt_Jpsi_hist");

    TH1D *eff_pair_mass_hist = (TH1D*)file->Get("eff_pair_mass_hist");
    TH1D *eff_cut_pair_mass_hist = (TH1D*)file->Get("eff_cut_pair_mass_hist");
    TH1D *eff_pair_mass_Jpsi_hist = (TH1D*)file->Get("eff_pair_mass_Jpsi_hist");
    TH1D *eff_cut_pair_mass_Jpsi_hist = (TH1D*)file->Get("eff_cut_pair_mass_Jpsi_hist");

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
    TH1D *dimuon_mass_hist = (TH1D*)file1->Get("dimuon_mass_hist");
    //cut_pair_mass_hist->SetTitle("; M_{#mu#mu}[MeV]; number of events");

    TH1D *L1_efficiency_hist = new TH1D("L1_efficiency_hist", "L1_efficiency_hist", 1000, 0, 10);

    //TCanvas *c1 = new TCanvas();
    //TCanvas *c2 = new TCanvas();
    //TCanvas *c3 = new TCanvas();
    //TCanvas *c4 = new TCanvas();
    //TCanvas *c5 = new TCanvas();
    //TCanvas *c6 = new TCanvas();
    //TCanvas *c7 = new TCanvas();
    //TCanvas *c8 = new TCanvas();

/*
    TH1 *frame = c1->DrawFrame(0.0, 0.0, 0.3, 1.1);
    frame->GetXaxis()->SetTitle("#DeltaR_{#mu#mu}at Muonspectrometer");
    frame->GetYaxis()->SetTitle("efficiency");
*/

    // efficiency
    TEfficiency *pEff_deltaR = new TEfficiency(*cut_pair_deltaR_hist, *pair_deltaR_hist);
    pEff_deltaR->SetTitle("efficiency;deltaR at vertex;efficiency");
    pEff_deltaR->SetMarkerStyle(4);
    pEff_deltaR->SetMarkerColor(2);
    pEff_deltaR->SetLineColor(2);
    // efficiency (deltaR at MS)
    TEfficiency *pEff_deltaR_MS = new TEfficiency(*fine_cut_pair_ext_deltaR_hist, *pair_ext_deltaR_hist);
    pEff_deltaR_MS->SetTitle("efficiency;deltaR at MS;efficiency");
    pEff_deltaR_MS->SetMarkerStyle(4);
    pEff_deltaR_MS->SetMarkerColor(2);
    pEff_deltaR_MS->SetLineColor(2);

    //efficiency(J/psi cut)
    TEfficiency *pEff_deltaR_Jpsi = new TEfficiency(*cut_pair_deltaR_Jpsi_hist, *pair_deltaR_Jpsi_hist);
    pEff_deltaR_Jpsi->SetTitle("efficiency Jpsi;deltaR at vertex;efficiency");
    pEff_deltaR_Jpsi->SetMarkerStyle(4);
    pEff_deltaR_Jpsi->SetMarkerColor(4);
    pEff_deltaR_Jpsi->SetLineColor(4);

    // efficiency (deltaR at MS)
    TEfficiency *pEff_deltaR_MS_Jpsi = new TEfficiency(*cut_pair_ext_deltaR_Jpsi_hist, *pair_ext_deltaR_Jpsi_hist);
    pEff_deltaR_MS_Jpsi->SetTitle("efficiency Jpsi;deltaR at MS;efficiency");
    pEff_deltaR_MS_Jpsi->SetMarkerStyle(4);
    pEff_deltaR_MS_Jpsi->SetMarkerColor(4);
    pEff_deltaR_MS_Jpsi->SetLineColor(4);
    
    TEfficiency *pEff_pt = new TEfficiency(*cut_pair_pt_hist, *pair_pt_hist);
    pEff_pt->SetTitle("efficiency;offline muon p_{T};efficiency");
    pEff_pt->SetMarkerStyle(4);
    pEff_pt->SetMarkerColor(2);
    pEff_pt->SetLineColor(2);
    TEfficiency *pEff_pt_Jpsi = new TEfficiency(*cut_pair_pt_Jpsi_hist, *pair_pt_Jpsi_hist);
    pEff_pt_Jpsi->SetTitle("efficiency;offline muon p_{T};efficiency");
    pEff_pt_Jpsi->SetMarkerStyle(4);
    pEff_pt_Jpsi->SetMarkerColor(4);
    pEff_pt_Jpsi->SetLineColor(4);

    /*
    TEfficiency *pEff_deltaR_Jpsi_MC = new TEfficiency(*cut_pair_deltaR_Jpsi_hist_MC, *pair_deltaR_Jpsi_hist_MC);
    pEff_deltaR_Jpsi_MC->SetTitle("efficiency Jpsi;deltaR at vertex;efficiency");
    pEff_deltaR_Jpsi_MC->SetMarkerStyle(4);
    pEff_deltaR_Jpsi_MC->SetMarkerColor (1);
    pEff_deltaR_Jpsi_MC->SetLineColor (1);
    */
    /*
    TEfficiency *pEff_deltaR_MS_Jpsi_MC = new TEfficiency(*cut_pair_ext_deltaR_Jpsi_hist_MC, *pair_ext_deltaR_Jpsi_hist_MC);
    pEff_deltaR_MS_Jpsi_MC->SetTitle("efficiency Jpsi;deltaR at MS;efficiency");
    pEff_deltaR_MS_Jpsi_MC->SetMarkerStyle(4);
    pEff_deltaR_MS_Jpsi_MC->SetMarkerColor (1);
    pEff_deltaR_MS_Jpsi_MC->SetLineColor (1);
    */
    //TEfficiency *pEff_deltaPhi = new TEfficiency(*cut_pair_deltaPhi_hist, *pair_deltaPhi_hist);
    //pEff_deltaPhi->SetTitle("efficiency;deltaPhi,vertex;efficiency");


    TEfficiency *pEff_mass_Jpsi = new TEfficiency(*eff_cut_pair_mass_Jpsi_hist, *eff_pair_mass_Jpsi_hist);
    //pEff_ext_2MU10->SetTitle("2MU10 efficiency;deltaR,extrapolate;efficiency");
    //pEff_ext_2MU10->SetTitle(";#DeltaR_{#mu#mu}at Muonspectrometer;efficiency");
    pEff_mass_Jpsi->SetTitle("efficiency; invariant mass;efficiency");
    //pEff_ext_2MU10->SetMarkerStyle(20);

    TEfficiency *pEff_mass = new TEfficiency(*eff_cut_pair_mass_hist, *eff_pair_mass_hist);
    pEff_mass->SetTitle("efficiency;invariant mass;efficiency");


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

    TLegend *legend1 = new TLegend( 0.57, 0.75, 0.9, 0.85) ; //（）の中は位置の指定（左下の x , y 、右上の x , y ）
    legend1->AddEntry( pEff_deltaR, "(a)w/o J/psi mass cut" , "lp") ; // AddEntry( pointer , "interpretation" , "option" )
    legend1->AddEntry( pEff_deltaR_Jpsi, "(b)w/ J/psi mass cut" , "lp") ; // option は　"f"=box, "l"="L"=line, "p"=marker
    //legend1->AddEntry( pEff_ext_2MUON, "(a) or (b)" , "lp") ; // option は　"f"=box, "l"="L"=line, "p"=marker
    legend1->SetFillColor(0);
    legend1->SetBorderSize(0);

    TLegend *legend2 = new TLegend( 0.17, 0.75, 0.5, 0.85) ; //（）の中は位置の指定（左下の x , y 、右上の x , y ）
    legend2->AddEntry( pEff_deltaR_MS, "(a)w/o J/psi mass cut" , "lp") ; // AddEntry( pointer , "interpretation" , "option" )
    legend2->AddEntry( pEff_deltaR_MS_Jpsi, "(b)w/ J/psi mass cut" , "lp") ; // option は　"f"=box, "l"="L"=line, "p"=marker
    //legend2->AddEntry( pEff_ext_2MUON, "(a) or (b)" , "lp") ; // option は　"f"=box, "l"="L"=line, "p"=marker
    legend2->SetFillColor(0);
    legend2->SetBorderSize(0);

    TLegend *legend3 = new TLegend( 0.17, 0.75, 0.5, 0.85) ; //（）の中は位置の指定（左下の x , y 、右上の x , y ）
    legend3->AddEntry( pEff_pt, "(a)w/o J/psi mass cut" , "lp") ; // AddEntry( pointer , "interpretation" , "option" )
    legend3->AddEntry( pEff_pt_Jpsi, "(b)w/ J/psi mass cut" , "lp") ; // option は　"f"=box, "l"="L"=line, "p"=marker
    //legend2->AddEntry( pEff_ext_2MUON, "(a) or (b)" , "lp") ; // option は　"f"=box, "l"="L"=line, "p"=marker
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
    TH1 *frame1 = c1->DrawFrame(0.0, 0.0, 0.3, 1);
    frame1->GetXaxis()->SetTitle("#DeltaR_{#mu#mu}at vertex");
    frame1->GetYaxis()->SetTitle("efficiency");
    pEff_deltaR->Draw("same");
    pEff_deltaR_Jpsi->Draw("same");
    legend1->Draw("same");

    TCanvas *c2 = new TCanvas();
    TH1 *frame2 = c2->DrawFrame(0.0, 0.0, 0.3, 1);
    frame2->GetXaxis()->SetTitle("#DeltaR_{#mu#mu}at Muonspectrometer");
    frame2->GetYaxis()->SetTitle("efficiency");
    pEff_deltaR_MS->Draw("same");
    pEff_deltaR_MS_Jpsi->Draw("same");
    legend2->Draw("same");


    TCanvas *c3 = new TCanvas();
    TH1 *frame3 = c3->DrawFrame(0.0, 0.0, 0.3, 1);
    frame3->GetXaxis()->SetTitle("#DeltaR_{#mu#mu}at vertex");
    frame3->GetYaxis()->SetTitle("efficiency");
    pEff_deltaR_Jpsi->Draw("same");
    //pEff_deltaR_Jpsi_MC->Draw("same");
    //legend1->Draw("same");

    TCanvas *c4 = new TCanvas();
    TH1 *frame4 = c4->DrawFrame(0.0, 0.0, 0.3, 1);
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

    TCanvas *c7 = new TCanvas();
    TH1 *frame7 = c7->DrawFrame(0.0, 0.0, 100, 1);
    frame7->GetXaxis()->SetTitle("offline muon p_{T}");
    frame7->GetYaxis()->SetTitle("efficiency");
    pEff_pt->Draw("same");
    pEff_pt_Jpsi->Draw("same");
    legend3->Draw("same");
/*
    TCanvas *c8 = new TCanvas();
    TH1 *frame8 = c8->DrawFrame(0.0, 0.0, 100, 1);
    frame8->GetXaxis()->SetTitle("offline muon p_{T}");
    frame8->GetYaxis()->SetTitle("efficiency");
    pEff_pt_Jpsi->Draw("same");
*/
    //ATLASLabel(0.53, 0.85, 1, 0.12, 0.05);

}