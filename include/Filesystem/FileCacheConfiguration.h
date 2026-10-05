#pragma once

// Layout carrier for the original cache configuration and path string pool.
// Its grouping preserves storage order, not inferred original declaration types.
struct FileCacheConfiguration
{
    unsigned int compressionPrefixBytes[2];
    char pack_font_gp2[14];
    char prm_level0_bin[15];
    char prm_level9_bin[15];
    char prm_encbtl_bin[15];
    char prm_level5_bin[15];
    char prm_level4_bin[15];
    char ani_obj_tm_gp2[15];
    char prm_enchab_gp2[15];
    char prm_level7_bin[15];
    char prm_level8_bin[15];
    char prm_level6_bin[15];
    char prm_actmsg_gp2[15];
    char prm_level2_bin[15];
    char prm_itemdt_gp2[15];
    char ani_obj_mm_pac[15];
    char prm_level3_bin[15];
    char prm_encfld_bin[15];
    char prm_actexp_gp2[15];
    char prm_level1_bin[15];
    char prm_level11_bin[16];
    char prm_level12_bin[16];
    char prm_encmons_bin[16];
    char prm_actdt_b_gp2[16];
    char prm_actdt_a_gp2[16];
    char prm_actname_nat[16];
    char prm_sklname_gp2[16];
    char prm_level10_bin[16];
    char prm_itemname_gp2[17];
    char prm_itemexpl_gp2[17];
    char prm_item_tmn_gp2[17];
    char prm_mon_trv2_gp2[17];
    char map_maplist9_bin[17];
    char prm_itemdt_t_gp2[17];
    char prm_itemdt_w_gp2[17];
    char prm_mon_list_gp2[17];
    char prm_itemsort_gp2[17];
    char prm_mon_data_gp2[17];
    char prm_mon_trv1_gp2[17];
    char pack_lv5_path_gp2[18];
    char pack_lv5_enemy_gp2[19];
    char prm_mons_info2_nat[19];
    char prm_skilltable_bin[19];
    char prm_spelltable_bin[19];
    char prm_itembtlprm_nat[19];
    char prm_mon_btldata_nat[20];
    char prm_mon_moddata_nat[20];
    char prm_fld_mondata_bin[20];
    char prm_item_fn_div_nat[20];
    char prm_iteminfo_en_gp2[20];
    char bin_menu_str_tm_gp2[20];
    char prm_iteminfo_fr_gp2[20];
    char prm_iteminfo_it_gp2[20];
    char prm_iteminfo_de_gp2[20];
    char prm_iteminfo_es_gp2[20];
    char pack_lv5_minimap_gp2[21];
    char pack_lv5_minimapt_gp2[22];
    char pack_lv5_chara_mp_gp2[22];
    char pack_lv5_chara_pc_gp2[22];
    char pack_lv5_chara_pd_gp2[22];
    char pack_lv5_font_lv5_gp2[22];
    char effect_ev999991500_chr[23];
    unsigned char alignmentPadding[2];
    char root[8];
};

extern FileCacheConfiguration gFileCacheConfiguration;
