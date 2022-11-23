void slice_method(){

  UInt_t n_ph, n_jet, n_e_looseBL, n_mu, ph_isem;
  Double_t ph_pt, ph_phi, ph_eta, ph_iso_et40, ph_iso_et20, ph_iso_pt, ph_z_point;
  Double_t jet_lead_phi,jet_lead_pt, jet_lead_eta, jet_sublead_phi, metTST_pt, metTST_phi, metTSTsignif;
  Double_t error_FR_data_1, error_CR1_data_1, error_CR1_data_2, error_CR1_data_3, error_CR1_data_4, error_CR1_data_5, error_CR2_data_1, error_CR2_data_2, error_CR2_data_3, error_CR2_data_4, error_CR2_data_5;
  Double_t N_FR_data_1, N_CR1_data_1, N_CR1_data_2, N_CR1_data_3, N_CR1_data_4, N_CR1_data_5, N_CR2_data_1, N_CR2_data_2, N_CR2_data_3, N_CR2_data_4, N_CR2_data_5;
  Int_t nbins=3;
  Double_t xbins[4] = {120, 170, 270, 1200};

  TH1D *hist_FR_data_1 = new TH1D ("hist1", "hist1", nbins, 0, 1200);
  TH1D *hist_FR_data_2 = new TH1D ("hist2", "hist2", nbins, 0, 1200);
  TH1D *hist_FR_data_3 = new TH1D ("hist3", "hist3", nbins, 0, 1200);
  TH1D *hist_FR_data_4 = new TH1D ("hist4", "hist4", nbins, 0, 1200);
  TH1D *hist_FR_data_5 = new TH1D ("hist5", "hist5", nbins, 0, 1200);

  TH1D *hist_CR1_data_1 = new TH1D ("hist1", "hist1", nbins, 0, 1200);
  TH1D *hist_CR1_data_2 = new TH1D ("hist2", "hist2", nbins, 0, 1200);
  TH1D *hist_CR1_data_3 = new TH1D ("hist3", "hist3", nbins, 0, 1200);
  TH1D *hist_CR1_data_4 = new TH1D ("hist4", "hist4", nbins, 0, 1200);
  TH1D *hist_CR1_data_5= new TH1D ("hist5", "hist5", nbins, 0, 1200);

  TH1D *hist_CR2_data_1 = new TH1D ("hist1", "hist1", nbins, 0, 1200);
  TH1D *hist_CR2_data_2 = new TH1D ("hist2", "hist2", nbins, 0, 1200);
  TH1D *hist_CR2_data_3 = new TH1D ("hist3", "hist3", nbins, 0, 1200);
  TH1D *hist_CR2_data_4 = new TH1D ("hist4", "hist4", nbins, 0, 1200);
  TH1D *hist_CR2_data_5 = new TH1D ("hist5", "hist5", nbins, 0, 1200);

  hist_FR_data_1 = dynamic_cast<TH1D*>(hist_FR_data_1->Rebin(nbins,"hist1",xbins));
  hist_FR_data_2 = dynamic_cast<TH1D*>(hist_FR_data_2->Rebin(nbins,"hist2",xbins));
  hist_FR_data_3 = dynamic_cast<TH1D*>(hist_FR_data_3->Rebin(nbins,"hist3",xbins));
  hist_FR_data_4 = dynamic_cast<TH1D*>(hist_FR_data_4->Rebin(nbins,"hist4",xbins));
  hist_FR_data_5 = dynamic_cast<TH1D*>(hist_FR_data_5->Rebin(nbins,"hist5",xbins));

  hist_CR1_data_1 = dynamic_cast<TH1D*>(hist_CR1_data_1->Rebin(nbins,"hist1",xbins));
  hist_CR1_data_2 = dynamic_cast<TH1D*>(hist_CR1_data_2->Rebin(nbins,"hist2",xbins));
  hist_CR1_data_3 = dynamic_cast<TH1D*>(hist_CR1_data_3->Rebin(nbins,"hist3",xbins));
  hist_CR1_data_4 = dynamic_cast<TH1D*>(hist_CR1_data_4->Rebin(nbins,"hist4",xbins));
  hist_CR1_data_5 = dynamic_cast<TH1D*>(hist_CR1_data_5->Rebin(nbins,"hist5",xbins));

  hist_CR2_data_1 = dynamic_cast<TH1D*>(hist_CR2_data_1->Rebin(nbins,"hist1",xbins));
  hist_CR2_data_2 = dynamic_cast<TH1D*>(hist_CR2_data_2->Rebin(nbins,"hist2",xbins));
  hist_CR2_data_3 = dynamic_cast<TH1D*>(hist_CR2_data_3->Rebin(nbins,"hist3",xbins));
  hist_CR2_data_4 = dynamic_cast<TH1D*>(hist_CR2_data_4->Rebin(nbins,"hist4",xbins));
  hist_CR2_data_5 = dynamic_cast<TH1D*>(hist_CR2_data_5->Rebin(nbins,"hist5",xbins));

  const char *path = "/home/valerian/programs/R_factor_MC/private/data_full_checked/data15-18.reproc-30-09-21_full_checked.root";

    TFile *data = new TFile(path, "READ");
    TTree *tree = (TTree*)data->Get("output_tree");

    tree->SetBranchAddress("n_ph", &n_ph);
    tree->SetBranchAddress("n_jet", &n_jet);
    tree->SetBranchAddress("n_e_looseBL", &n_e_looseBL);
    tree->SetBranchAddress("n_mu", &n_mu);
    tree->SetBranchAddress("ph_pt",&ph_pt);
    tree->SetBranchAddress("ph_phi",&ph_phi);
    tree->SetBranchAddress("ph_eta",&ph_eta);
    tree->SetBranchAddress("ph_iso_et20", &ph_iso_et20);
    tree->SetBranchAddress("ph_iso_pt", &ph_iso_pt);
    tree->SetBranchAddress("ph_isem", &ph_isem);
    tree->SetBranchAddress("ph_z_point", &ph_z_point);
    tree->SetBranchAddress("jet_lead_phi",&jet_lead_phi);
    tree->SetBranchAddress("jet_lead_pt",&jet_lead_pt);
    tree->SetBranchAddress("jet_lead_eta",&jet_lead_eta);
    tree->SetBranchAddress("metTST_pt", &metTST_pt);
    tree->SetBranchAddress("metTST_phi",&metTST_phi);
    tree->SetBranchAddress("metTSTsignif", &metTSTsignif);

    int entry = (int)tree->GetEntries();

    for (int i=0; i<entry; i++){
    tree->GetEntry(i);

    TLorentzVector *v1 = new TLorentzVector();
    TLorentzVector *v2 = new TLorentzVector();
    TLorentzVector *v3 = new TLorentzVector();
    v1->SetPtEtaPhiM(metTST_pt, 0, metTST_phi, 0);
    v2->SetPtEtaPhiM(jet_lead_pt, jet_lead_eta, jet_lead_phi, 0);
    v3->SetPtEtaPhiM(ph_pt, ph_eta, ph_phi, 0);
    Double_t dphi_1=abs((*v1).DeltaPhi(*v3));
    Double_t dphi_2=abs((*v1).DeltaPhi(*v2));

    if (ph_pt <= 150) continue;
    if (n_ph !=1 || n_e_looseBL !=0 || n_mu!=0) continue;
    if (fabs(ph_z_point) >= 250) continue;
    if (ph_isem!=0) continue;

    bool str_kinem_select = (metTSTsignif <= 11 || metTST_pt <= 130 || dphi_1 <= 0.7 || (n_jet >=1 && dphi_2 <= 0.4));
    Double_t Iso_cal = ph_iso_et20/ph_pt;
    Double_t Iso_track = ph_iso_pt/ph_pt;

    if (Iso_cal > 0.065 && Iso_cal < 0.080 && Iso_track > 0.05) hist_CR1_data_1->Fill(metTST_pt, 1.0);
    if (Iso_cal > 0.080 && Iso_cal < 0.095 && Iso_track > 0.05) hist_CR1_data_2->Fill(metTST_pt, 1.0);
    if (Iso_cal > 0.095 && Iso_cal < 0.115 && Iso_track > 0.05) hist_CR1_data_3->Fill(metTST_pt, 1.0);
    if (Iso_cal > 0.115 && Iso_cal < 0.140 && Iso_track > 0.05) hist_CR1_data_4->Fill(metTST_pt, 1.0);
    if (Iso_cal > 0.140 && Iso_track > 0.05) hist_CR1_data_5->Fill(metTST_pt, 1.0);

    if (Iso_cal > 0.065 && Iso_cal < 0.080 && Iso_track > 0.05 && str_kinem_select==0) hist_CR2_data_1->Fill(metTST_pt, 1.0);
    if (Iso_cal > 0.080 && Iso_cal < 0.095 && Iso_track > 0.05 && str_kinem_select==0) hist_CR2_data_2->Fill(metTST_pt, 1.0);
    if (Iso_cal > 0.095 && Iso_cal < 0.115 && Iso_track > 0.05 && str_kinem_select==0) hist_CR2_data_3->Fill(metTST_pt, 1.0);
    if (Iso_cal > 0.115 && Iso_cal < 0.140 && Iso_track > 0.05 && str_kinem_select==0) hist_CR2_data_4->Fill(metTST_pt, 1.0);
    if (Iso_cal > 0.140 && Iso_track > 0.05 && str_kinem_select==0) hist_CR2_data_5->Fill(metTST_pt, 1.0);

    if (Iso_cal < 0.065 && Iso_track < 0.05) hist_FR_data_1->Fill(metTST_pt, 1.0);
    if (Iso_cal < 0.065 && Iso_track < 0.05) hist_FR_data_2->Fill(metTST_pt, 1.0);
    if (Iso_cal < 0.065 && Iso_track < 0.05) hist_FR_data_3->Fill(metTST_pt, 1.0);
    if (Iso_cal < 0.065 && Iso_track < 0.05) hist_FR_data_4->Fill(metTST_pt, 1.0);
    if (Iso_cal < 0.065 && Iso_track < 0.05) hist_FR_data_5->Fill(metTST_pt, 1.0);
  }

  Double_t overflow_FR_1 = hist_FR_data_1->GetBinContent(nbins)+hist_FR_data_1->GetBinContent(nbins+1);
  Double_t overflow_FR_2 = hist_FR_data_2->GetBinContent(nbins)+hist_FR_data_2->GetBinContent(nbins+1);
  Double_t overflow_FR_3 = hist_FR_data_3->GetBinContent(nbins)+hist_FR_data_3->GetBinContent(nbins+1);
  Double_t overflow_FR_4 = hist_FR_data_4->GetBinContent(nbins)+hist_FR_data_4->GetBinContent(nbins+1);
  Double_t overflow_FR_5 = hist_FR_data_5->GetBinContent(nbins)+hist_FR_data_5->GetBinContent(nbins+1);

  Double_t overflow_CR1_1 = hist_CR1_data_1->GetBinContent(nbins)+hist_CR1_data_1->GetBinContent(nbins+1);
  Double_t overflow_CR1_2 = hist_CR1_data_2->GetBinContent(nbins)+hist_CR1_data_2->GetBinContent(nbins+1);
  Double_t overflow_CR1_3 = hist_CR1_data_3->GetBinContent(nbins)+hist_CR1_data_3->GetBinContent(nbins+1);
  Double_t overflow_CR1_4 = hist_CR1_data_4->GetBinContent(nbins)+hist_CR1_data_4->GetBinContent(nbins+1);
  Double_t overflow_CR1_5 = hist_CR1_data_5->GetBinContent(nbins)+hist_CR1_data_5->GetBinContent(nbins+1);

  Double_t overflow_CR2_1= hist_CR2_data_1->GetBinContent(nbins)+hist_CR2_data_1->GetBinContent(nbins+1);
  Double_t overflow_CR2_2= hist_CR2_data_2->GetBinContent(nbins)+hist_CR2_data_2->GetBinContent(nbins+1);
  Double_t overflow_CR2_3= hist_CR2_data_3->GetBinContent(nbins)+hist_CR2_data_3->GetBinContent(nbins+1);
  Double_t overflow_CR2_4= hist_CR2_data_4->GetBinContent(nbins)+hist_CR2_data_4->GetBinContent(nbins+1);
  Double_t overflow_CR2_5= hist_CR2_data_5->GetBinContent(nbins)+hist_CR2_data_5->GetBinContent(nbins+1);

  hist_FR_data_1->SetBinContent(nbins, overflow_FR_1);
  hist_FR_data_2->SetBinContent(nbins, overflow_FR_2);
  hist_FR_data_3->SetBinContent(nbins, overflow_FR_3);
  hist_FR_data_4->SetBinContent(nbins, overflow_FR_4);
  hist_FR_data_5->SetBinContent(nbins, overflow_FR_5);

  hist_CR1_data_1->SetBinContent(nbins, overflow_CR1_1);
  hist_CR1_data_2->SetBinContent(nbins, overflow_CR1_2);
  hist_CR1_data_3->SetBinContent(nbins, overflow_CR1_3);
  hist_CR1_data_4->SetBinContent(nbins, overflow_CR1_4);
  hist_CR1_data_5->SetBinContent(nbins, overflow_CR1_5);

  hist_CR2_data_1->SetBinContent(nbins, overflow_CR2_1);
  hist_CR2_data_2->SetBinContent(nbins, overflow_CR2_2);
  hist_CR2_data_3->SetBinContent(nbins, overflow_CR2_3);
  hist_CR2_data_4->SetBinContent(nbins, overflow_CR2_4);
  hist_CR2_data_5->SetBinContent(nbins, overflow_CR2_5);

  Double_t overflow_err_FR_1 = sqrt(pow(hist_FR_data_1->GetBinError(nbins), 2) + pow(hist_FR_data_1->GetBinError(nbins+1), 2));
  Double_t overflow_err_FR_2 = sqrt(pow(hist_FR_data_2->GetBinError(nbins), 2) + pow(hist_FR_data_2->GetBinError(nbins+1), 2));
  Double_t overflow_err_FR_3 = sqrt(pow(hist_FR_data_3->GetBinError(nbins), 2) + pow(hist_FR_data_3->GetBinError(nbins+1), 2));
  Double_t overflow_err_FR_4 = sqrt(pow(hist_FR_data_4->GetBinError(nbins), 2) + pow(hist_FR_data_4->GetBinError(nbins+1), 2));
  Double_t overflow_err_FR_5 = sqrt(pow(hist_FR_data_5->GetBinError(nbins), 2) + pow(hist_FR_data_5->GetBinError(nbins+1), 2));

  Double_t overflow_err_CR1_1 = sqrt(pow(hist_CR1_data_1->GetBinError(nbins), 2) + pow(hist_CR1_data_1->GetBinError(nbins+1), 2));
  Double_t overflow_err_CR1_2 = sqrt(pow(hist_CR1_data_2->GetBinError(nbins), 2) + pow(hist_CR1_data_2->GetBinError(nbins+1), 2));
  Double_t overflow_err_CR1_3 = sqrt(pow(hist_CR1_data_3->GetBinError(nbins), 2) + pow(hist_CR1_data_3->GetBinError(nbins+1), 2));
  Double_t overflow_err_CR1_4 = sqrt(pow(hist_CR1_data_4->GetBinError(nbins), 2) + pow(hist_CR1_data_4->GetBinError(nbins+1), 2));
  Double_t overflow_err_CR1_5 = sqrt(pow(hist_CR1_data_5->GetBinError(nbins), 2) + pow(hist_CR1_data_5->GetBinError(nbins+1), 2));

  Double_t overflow_err_CR2_1 = sqrt(pow(hist_CR2_data_1->GetBinError(nbins), 2) + pow(hist_CR2_data_1->GetBinError(nbins+1), 2));
  Double_t overflow_err_CR2_2 = sqrt(pow(hist_CR2_data_2->GetBinError(nbins), 2) + pow(hist_CR2_data_2->GetBinError(nbins+1), 2));
  Double_t overflow_err_CR2_3 = sqrt(pow(hist_CR2_data_3->GetBinError(nbins), 2) + pow(hist_CR2_data_3->GetBinError(nbins+1), 2));
  Double_t overflow_err_CR2_4 = sqrt(pow(hist_CR2_data_4->GetBinError(nbins), 2) + pow(hist_CR2_data_4->GetBinError(nbins+1), 2));
  Double_t overflow_err_CR2_5 = sqrt(pow(hist_CR2_data_5->GetBinError(nbins), 2) + pow(hist_CR2_data_5->GetBinError(nbins+1), 2));

  hist_FR_data_1->SetBinError(nbins, overflow_err_FR_1);
  hist_FR_data_2->SetBinError(nbins, overflow_err_FR_2);
  hist_FR_data_3->SetBinError(nbins, overflow_err_FR_3);
  hist_FR_data_4->SetBinError(nbins, overflow_err_FR_4);
  hist_FR_data_5->SetBinError(nbins, overflow_err_FR_5);

  hist_CR1_data_1->SetBinError(nbins, overflow_err_CR1_1);
  hist_CR1_data_2->SetBinError(nbins, overflow_err_CR1_2);
  hist_CR1_data_3->SetBinError(nbins, overflow_err_CR1_3);
  hist_CR1_data_4->SetBinError(nbins, overflow_err_CR1_4);
  hist_CR1_data_5->SetBinError(nbins, overflow_err_CR1_5);

  hist_CR2_data_1->SetBinError(nbins, overflow_err_CR2_1);
  hist_CR2_data_2->SetBinError(nbins, overflow_err_CR2_2);
  hist_CR2_data_3->SetBinError(nbins, overflow_err_CR2_3);
  hist_CR2_data_4->SetBinError(nbins, overflow_err_CR2_4);
  hist_CR2_data_5->SetBinError(nbins, overflow_err_CR2_5);

  TFile *file_FR = new TFile ("FR_data.root","UPDATE");
  hist_FR_data_1->Write();
  hist_FR_data_2->Write();
  hist_FR_data_3->Write();
  hist_FR_data_4->Write();
  hist_FR_data_5->Write();
  file_FR->Close();

  TFile *file_CR1 = new TFile ("CR1_data.root","UPDATE");
  hist_CR1_data_1->Write();
  hist_CR1_data_2->Write();
  hist_CR1_data_3->Write();
  hist_CR1_data_4->Write();
  hist_CR1_data_5->Write();
  file_CR1->Close();

  N_FR_data_1=hist_FR_data_1->IntegralAndError(1, nbins, error_FR_data_1, "");

  N_CR1_data_1=hist_CR1_data_1->IntegralAndError(1, nbins, error_CR1_data_1, "");
  N_CR1_data_2=hist_CR1_data_2->IntegralAndError(1, nbins, error_CR1_data_2, "");
  N_CR1_data_3=hist_CR1_data_3->IntegralAndError(1, nbins, error_CR1_data_3, "");
  N_CR1_data_4=hist_CR1_data_4->IntegralAndError(1, nbins, error_CR1_data_4, "");
  N_CR1_data_5=hist_CR1_data_5->IntegralAndError(1, nbins, error_CR1_data_5, "");

  N_CR2_data_1=hist_CR2_data_1->IntegralAndError(1, nbins, error_CR2_data_1, "");
  N_CR2_data_2=hist_CR2_data_2->IntegralAndError(1, nbins, error_CR2_data_2, "");
  N_CR2_data_3=hist_CR2_data_3->IntegralAndError(1, nbins, error_CR2_data_3, "");
  N_CR2_data_4=hist_CR2_data_4->IntegralAndError(1, nbins, error_CR2_data_4, "");
  N_CR2_data_5=hist_CR2_data_5->IntegralAndError(1, nbins, error_CR2_data_5, "");

  std::cout <<"        N_FR_data=" << N_FR_data_1 << " +- " << error_FR_data_1 << '\n';
  std::cout << "" << '\n';

  std::cout << "slice 1 " << " N_CR1_data_1=" << N_CR1_data_1 << " +- " << error_CR1_data_1 << "    N_CR2_data_1=" << N_CR2_data_1 << " +- " << error_CR2_data_1 << '\n';
  std::cout << "" << '\n';

  std::cout << "slice 2 " << " N_CR1_data_2=" << N_CR1_data_2 << " +- " << error_CR1_data_2 << "    N_CR2_data_2=" << N_CR2_data_2 << " +- " << error_CR2_data_2 << '\n';
  std::cout << "" << '\n';

  std::cout << "slice 3 " << " N_CR1_data_3=" << N_CR1_data_3 << " +- " << error_CR1_data_3 << "     N_CR2_data_3_data=" << N_CR2_data_3<< " +- " << error_CR2_data_3 << '\n';
  std::cout << "" << '\n';

  std::cout << "slice 4 " << " N_CR1_data_4=" << N_CR1_data_4 << " +- " << error_CR1_data_4 << "         N_CR2_data_4=" << N_CR2_data_4 << " +- " << error_CR2_data_4 << '\n';
  std::cout << "" << '\n';

  std::cout << "slice 5 " <<" N_CR1_data_5=" << N_CR1_data_5 << " +- " << error_CR1_data_5 << "      N_CR2_data_5=" << N_CR2_data_5 << " +- " << error_CR2_data_5 << '\n';
  std::cout << "" << '\n';
}
