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
    d.SetTextSize(0.035);
    //d.DrawLatex(x, y-dely, "Data 2022, #sqrt{s}=13.6TeV");
    d.DrawLatex(x, y-dely, "triggered by isolated muon trigger, p_{T} #geq 24 GeV");
}

void eff_mu10(){

    gROOT->SetStyle("ATLAS");

    //TFile *file1 = new TFile("img0906/hist0906_mu10L2mt_v2.root");
    TFile *file1 = new TFile("img0915/hist0915_singlemuon.root");
    TFile *file2 = new TFile("img0915/hist0915_singlemuon_MC.root");
    //TFile *file2 = new TFile("img0905/hist0905_mu10L2mt_Zmumu.root");


    TH1D *singleMuonPt_hist = (TH1D*)file1->Get("singleMuonPt_hist");
    TH1D *singleMuonEta_hist = (TH1D*)file1->Get("singleMuonEta_hist");
    TH1D *singleMuonPhi_hist = (TH1D*)file1->Get("singleMuonPhi_hist");
    TH1D *cut_singleMuonPt_hist = (TH1D*)file1->Get("cut_singleMuonPt_hist");
    TH1D *cut_singleMuonEta_hist = (TH1D*)file1->Get("cut_singleMuonEta_hist");
    TH1D *cut_singleMuonPhi_hist = (TH1D*)file1->Get("cut_singleMuonPhi_hist");

    TH1D *singleMuonPt_hist_MC = (TH1D*)file2->Get("singleMuonPt_hist");
    TH1D *singleMuonEta_hist_MC = (TH1D*)file2->Get("singleMuonEta_hist");
    TH1D *singleMuonPhi_hist_MC = (TH1D*)file2->Get("singleMuonPhi_hist");
    TH1D *cut_singleMuonPt_hist_MC = (TH1D*)file2->Get("cut_singleMuonPt_hist");
    TH1D *cut_singleMuonEta_hist_MC = (TH1D*)file2->Get("cut_singleMuonEta_hist");
    TH1D *cut_singleMuonPhi_hist_MC = (TH1D*)file2->Get("cut_singleMuonPhi_hist");
/*
    TH1D *pair_mass_hist_mu10 = (TH1D*)file->Get("pair_mass_hist_mu10");
    TH1D *pair_deltaR_hist_mu10 = (TH1D*)file->Get("pair_deltaR_hist_mu10");
    TH1D *pair_ext_deltaR_hist_mu10 = (TH1D*)file->Get("pair_ext_deltaR_hist_mu10");
    TH1D *pair_deltaPhi_hist_mu10 = (TH1D*)file->Get("pair_deltaPhi_hist_mu10");
    TH1D *pair_ext_deltaPhi_hist_mu10 = (TH1D*)file->Get("pair_ext_deltaPhi_hist_mu10");
    TH1D *pair_pt_hist_mu10 = (TH1D*)file->Get("pair_pt_hist_mu10");
    TH1D *min_pt_hist_mu10 = (TH1D*)file->Get("min_pt_hist_mu10");
    TH1D *max_pt_hist_mu10 = (TH1D*)file->Get("max_pt_hist_mu10");

    TH1D *cut_pair_mass_hist_mu10 = (TH1D*)file->Get("cut_pair_mass_hist_mu10");
    TH1D *cut_pair_deltaR_hist_mu10 = (TH1D*)file->Get("cut_pair_deltaR_hist_mu10");
    TH1D *cut_pair_ext_deltaR_hist_mu10 = (TH1D*)file->Get("cut_pair_ext_deltaR_hist_mu10");
    TH1D *cut_pair_deltaPhi_hist_mu10 = (TH1D*)file->Get("cut_pair_deltaPhi_hist_mu10");
    TH1D *cut_pair_pt_hist_mu10 = (TH1D*)file->Get("cut_pair_pt_hist_mu10");
    TH1D *cut_min_pt_hist_mu10 = (TH1D*)file->Get("cut_min_pt_hist_mu10");
    TH1D *cut_max_pt_hist_mu10 = (TH1D*)file->Get("cut_max_pt_hist_mu10");

    TH1D *pair_mass_hist_2mu10 = (TH1D*)file->Get("pair_mass_hist_2mu10");
    TH1D *pair_deltaR_hist_2mu10 = (TH1D*)file->Get("pair_deltaR_hist_2mu10");
    TH1D *pair_ext_deltaR_hist_2mu10 = (TH1D*)file->Get("pair_ext_deltaR_hist_2mu10");
    TH1D *pair_deltaPhi_hist_2mu10 = (TH1D*)file->Get("pair_deltaPhi_hist_2mu10");
    TH1D *pair_ext_deltaPhi_hist_2mu10 = (TH1D*)file->Get("pair_ext_deltaPhi_hist_2mu10");
    TH1D *pair_pt_hist_2mu10 = (TH1D*)file->Get("pair_pt_hist_2mu10");
    TH1D *min_pt_hist_2mu10 = (TH1D*)file->Get("min_pt_hist_2mu10");
    TH1D *max_pt_hist_2mu10 = (TH1D*)file->Get("max_pt_hist_2mu10");

    TH1D *cut_pair_mass_hist_2mu10 = (TH1D*)file->Get("cut_pair_mass_hist_2mu10");
    TH1D *cut_pair_deltaR_hist_2mu10 = (TH1D*)file->Get("cut_pair_deltaR_hist_2mu10");
    TH1D *cut_pair_ext_deltaR_hist_2mu10 = (TH1D*)file->Get("cut_pair_ext_deltaR_hist_2mu10");
    TH1D *cut_pair_deltaPhi_hist_2mu10 = (TH1D*)file->Get("cut_pair_deltaPhi_hist_2mu10");
    TH1D *cut_pair_pt_hist_2mu10 = (TH1D*)file->Get("cut_pair_pt_hist_2mu10");
    TH1D *cut_min_pt_hist_2mu10 = (TH1D*)file->Get("cut_min_pt_hist_2mu10");
    TH1D *cut_max_pt_hist_2mu10 = (TH1D*)file->Get("cut_max_pt_hist_2mu10");

    TH1D *L1_efficiency_hist = new TH1D("L1_efficiency_hist", "L1_efficiency_hist", 1000, 0, 10);
*/
    //TCanvas *c1 = new TCanvas();
    //TCanvas *c2 = new TCanvas();
    //TCanvas *c3 = new TCanvas();
    //TCanvas *c4 = new TCanvas();
    //TCanvas *c5 = new TCanvas();
    //TCanvas *c6 = new TCanvas();
    //TCanvas *c7 = new TCanvas();
    //TCanvas *c8 = new TCanvas();

/*
    TH1 *frame = c4->DrawFrame(0.0, 0.0, 0.3, 1.1);
    frame->GetXaxis()->SetTitle("#DeltaR_{#mu#mu}at Muonspectrometer");
    frame->GetYaxis()->SetTitle("efficiency");
*/
/*
    //mu10 efficiency
    TEfficiency *pEff_deltaR_mu10 = new TEfficiency(*cut_pair_deltaR_hist_mu10, *pair_deltaR_hist_mu10);
    pEff_deltaR_mu10->SetTitle("efficiency mu10;deltaR at vertex;mu10 efficiency");
    // efficiency (deltaR at MS)
    TEfficiency *pEff_deltaR_MS_mu10 = new TEfficiency(*cut_pair_ext_deltaR_hist_mu10, *pair_ext_deltaR_hist_mu10);
    pEff_deltaR_MS_mu10->SetTitle("efficiency mu10;deltaR at MS;mu10 efficiency");

    TEfficiency *pEff_deltaPhi_mu10 = new TEfficiency(*cut_pair_deltaPhi_hist_mu10, *pair_deltaPhi_hist_mu10);
    pEff_deltaPhi_mu10->SetTitle("efficiency mu10;deltaPhi,vertex;mu10 efficiency");

    //2mu10 efficiency
    TEfficiency *pEff_deltaR_2mu10 = new TEfficiency(*cut_pair_deltaR_hist_2mu10, *pair_deltaR_hist_2mu10);
    pEff_deltaR_2mu10->SetTitle("efficiency 2mu10;deltaR at vertex;2mu10 efficiency");
    // efficiency (deltaR at MS)
    TEfficiency *pEff_deltaR_MS_2mu10 = new TEfficiency(*cut_pair_ext_deltaR_hist_2mu10, *pair_ext_deltaR_hist_2mu10);
    pEff_deltaR_MS_2mu10->SetTitle("efficiency 2mu10;deltaR at MS;2mu10 efficiency");

    TEfficiency *pEff_deltaPhi_2mu10 = new TEfficiency(*cut_pair_deltaPhi_hist_2mu10, *pair_deltaPhi_hist_2mu10);
    pEff_deltaPhi_2mu10->SetTitle("efficiency 2mu10;deltaPhi,vertex;2mu10 efficiency");
*/
/*
    TEfficiency *pEff_min_pt = new TEfficiency(*cut_min_pt_hist, *min_pt_hist);
    //pEff_ext_2MU10->SetTitle("2MU10 efficiency;deltaR,extrapolate;efficiency");
    //pEff_ext_2MU10->SetTitle(";#DeltaR_{#mu#mu}at Muonspectrometer;efficiency");
    pEff_min_pt->SetTitle("efficiency;pt_min mu;efficiency");
    //pEff_ext_2MU10->SetMarkerStyle(20);

    TEfficiency *pEff_max_pt = new TEfficiency(*cut_max_pt_hist, *max_pt_hist);
    pEff_max_pt->SetTitle("efficiency;pt_max mu;efficiency");
*/

    TEfficiency *pEff_singleMuonPt = new TEfficiency(*cut_singleMuonPt_hist, *singleMuonPt_hist);
    pEff_singleMuonPt->SetTitle("efficiency;pt;efficiency");
    pEff_singleMuonPt->SetMarkerStyle(4);
    pEff_singleMuonPt->SetMarkerColor(4);
    pEff_singleMuonPt->SetLineColor(4);
    
    TEfficiency *pEff_singleMuonPt_MC = new TEfficiency(*cut_singleMuonPt_hist_MC, *singleMuonPt_hist_MC);
    pEff_singleMuonPt_MC->SetTitle("efficiency;pt;efficiency");
    pEff_singleMuonPt_MC->SetMarkerStyle(1);
    pEff_singleMuonPt_MC->SetMarkerColor(2);
    pEff_singleMuonPt_MC->SetLineColor(2);

    //TEfficiency *pEff_singleMuonEta = new TEfficiency(*cut_singleMuonEta_hist, *singleMuonEta_hist);
    //pEff_singleMuonEta->SetTitle("efficiency;eta;efficiency");

    //TEfficiency *pEff_singleMuonPhi = new TEfficiency(*cut_singleMuonPhi_hist, *singleMuonPhi_hist);
    //pEff_singleMuonPhi->SetTitle("efficiency;phi;efficiency");

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

    TLegend *legend = new TLegend( 0.7, 0.25, 0.9, 0.35) ; //（）の中は位置の指定（左下の x , y 、右上の x , y ）
    legend->AddEntry( pEff_singleMuonPt, "Data 2023" , "lp") ; // AddEntry( pointer , "interpretation" , "option" )
    legend->AddEntry( pEff_singleMuonPt_MC, "J/#psi#rightarrow#mu#mu MC" , "l") ; // option は　"f"=box, "l"="L"=line, "p"=marker
    legend->SetFillColor(0);
    legend->SetBorderSize(0);


    TCanvas *c1 = new TCanvas();
    TH1 *frame1 = c1->DrawFrame(20, 0.0, 80, 1);
    frame1->GetXaxis()->SetTitle("p_{T}");
    frame1->GetYaxis()->SetTitle("L2mt reconstruction efficiency");
    pEff_singleMuonPt->Draw("SAME P");
    TH1D* hoge1 = dynamic_cast<TH1D*>(cut_singleMuonPt_hist_MC->Clone("hoge"));
    hoge1->Divide(singleMuonPt_hist_MC);
    hoge1->SetLineColor(2);
    hoge1->Draw("SAME HIST");
    legend->Draw("same");


/*
    TCanvas *c2 = new TCanvas();
    TH1 *frame2 = c2->DrawFrame(0.0, 0.0, 0.5, 1);
    frame2->GetXaxis()->SetTitle("#DeltaR_{#mu#mu}at MuonSpectrometer");
    frame2->GetYaxis()->SetTitle("mu10 efficiency");
    pEff_deltaR_MS_mu10->Draw("same");

    TCanvas *c3 = new TCanvas();
    TH1 *frame3 = c3->DrawFrame(0.0, 0.0, 0.5, 1);
    frame3->GetXaxis()->SetTitle("#DeltaPhi_{#mu#mu}at vertex");
    frame3->GetYaxis()->SetTitle("mu10 efficiency");
    pEff_deltaPhi_mu10->Draw("same");

    TCanvas *c4 = new TCanvas();
    TH1 *frame4 = c4->DrawFrame(0.0, 0.0, 0.5, 1);
    frame4->GetXaxis()->SetTitle("#DeltaR_{#mu#mu}at vertex");
    frame4->GetYaxis()->SetTitle("2muon efficiency");
    pEff_deltaR_2mu10->Draw("same");

    TCanvas *c5 = new TCanvas();
    TH1 *frame5 = c5->DrawFrame(0.0, 0.0, 0.5, 1);
    frame5->GetXaxis()->SetTitle("#DeltaR_{#mu#mu}at Muon Spectrometer");
    frame5->GetYaxis()->SetTitle("2muon efficiency");
    pEff_deltaR_MS_2mu10->Draw("same");

    TCanvas *c6 = new TCanvas();
    TH1 *frame6 = c6->DrawFrame(0.0, 0.0, 0.5, 1);
    frame6->GetXaxis()->SetTitle("#DeltaPhi_{#mu#mu}at vertex");
    frame6->GetYaxis()->SetTitle("2muon efficiency");
    pEff_deltaPhi_2mu10->Draw("same");
*/

    ATLASLabel(0.4, 0.5, 1, 0.12, 0.05);

    c1->SaveAs("L2mt_singlemuon_eff.png");

}