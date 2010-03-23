/* -*- mode: C; c-basic-offset: 4;  -*- */

/*
 * Copyright (C) 2006-2010 by Hannu Jokinen
 * Full copyright text is included in the software package.
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include <gdk/gdkkeysyms.h> 

#include "judoshiai.h"

#define NUM_CATEGORIES 32

struct offial_category {
    gchar *name; 
    gint maxage;
    gint match_time;
    gint gs_time;
    gint rest_time;
    struct {
        gint weight;
        gchar *weighttext;
    } weights[NUM_CAT_DEF_WEIGHTS];
};

struct offial_category official_categories[NUM_DRAWS][2][8] = {
    { // international
        { // men
            {
                "Men", 1000, 300, 180, 600, // name, max age, match gs rest times 
                {{60000, "60"}, {66000, "66"}, {73000, "73"}, 
                 {81000, "81"}, {90000, "90"}, {100000, "100"}, {0, NULL}}
            }, {
                "Men", 19, 240, 180, 600, // name, max age, match gs rest times 
                {{55000, "55"}, {60000, "60"}, {66000, "66"}, {73000, "73"}, 
                 {81000, "81"}, {90000, "90"}, {100000, "100"}, {0, NULL}}
            }, {
                "Men", 16, 180, 120, 600, // name, max age, match gs rest times 
                {{45000, "45"}, {50000, "50"}, {55000, "55"}, {60000, "60"}, 
                 {66000, "66"}, {73000, "73"}, {81000, "81"}, {90000, "90"}, {0, NULL}}
            }, { NULL, 0, 0, 0, 0, {{0, NULL}}}

        }, { // women
            {
                "Women", 1000, 300, 180, 600, // name, max age, match gs rest times 
                {{48000, "48"}, {52000, "52"}, {57000, "57"}, 
                 {63000, "63"}, {70000, "70"}, {78000, "78"}, {0, NULL}}
            }, {
                "Women", 19, 240, 180, 600, // name, max age, match gs rest times 
                {{44000, "44"}, {48000, "48"}, {52000, "52"}, {57000, "57"}, 
                 {63000, "63"}, {70000, "70"}, {78000, "78"}, {0, NULL}}
            }, {
                "Women", 16, 180, 120, 600, // name, max age, match gs rest times 
                {{44000, "44"}, {48000, "48"}, {52000, "52"}, {57000, "57"}, 
                 {63000, "63"}, {70000, "70"}, {0, NULL}}
            }, { NULL, 0, 0, 0, 0, {{0, NULL}}}
        }
    }, { // finnish
        { // men
            {
                "M", 1000, 300, 180, 600, // name, max age, match gs rest times 
                {{60000, "60"}, {66000, "66"}, {73000, "73"}, 
                 {81000, "81"}, {90000, "90"}, {100000, "100"}, {0, NULL}}
            }, {
                "AP", 19, 240, 180, 600, // name, max age, match gs rest times 
                {{55000, "55"}, {60000, "60"}, {66000, "66"}, {73000, "73"}, 
                 {81000, "81"}, {90000, "90"}, {0, NULL}}
            }, {
                "BP", 16, 180, 120, 600, // name, max age, match gs rest times 
                {{45000, "45"}, {50000, "50"}, {55000, "55"}, {60000, "60"}, 
                 {66000, "66"}, {73000, "73"}, {81000, "81"}, {0, NULL}}
            }, {
                "CP", 14, 180, 120, 180, // name, max age, match gs rest times 
                {{34000, "34"}, {38000, "38"}, {42000, "42"}, {46000, "46"}, 
                 {50000, "50"}, {55000, "55"}, {60000, "60"}, {66000, "66"}, {0, NULL}}
            }, {
                "DP", 12, 120, 60, 180, // name, max age, match gs rest times 
                {{30000, "30"}, {34000, "34"}, {38000, "38"}, {42000, "42"}, 
                 {46000, "46"}, {50000, "50"}, {55000, "55"}, {0, NULL}}
            }, {
                "EP", 10, 120, 60, 180, // name, max age, match gs rest times 
                {{27000, "27"}, {30000, "30"}, {34000, "34"}, {38000, "38"}, {42000, "42"}, 
                 {46000, "46"}, {50000, "50"}, {55000, "55"}, {0, NULL}}
            }, { NULL, 0, 0, 0, 0, {{0, NULL}}}
        }, { // women
            {
                "N", 1000, 300, 180, 600, // name, max age, match gs rest times 
                {{48000, "48"}, {52000, "52"}, {57000, "57"}, 
                 {63000, "63"}, {70000, "70"}, {78000, "78"}, {0, NULL}}
            }, {
                "AT", 19, 240, 180, 600, // name, max age, match gs rest times 
                {{48000, "48"}, {52000, "52"}, {57000, "57"}, 
                 {63000, "63"}, {70000, "70"}, {0, NULL}}
            }, {
                "BT", 16, 180, 120, 600, // name, max age, match gs rest times 
                {{44000, "44"}, {48000, "48"}, {52000, "52"}, {57000, "57"}, 
                 {63000, "63"}, {0, NULL}}
            }, {
                "CT", 14, 180, 120, 180, // name, max age, match gs rest times 
                {{32000, "32"}, {36000, "36"}, {40000, "40"}, {44000, "44"}, 
                 {48000, "48"}, {52000, "52"}, {57000, "57"}, {63000, "63"}, {0, NULL}}
            }, {
                "DT", 12, 120, 60, 180, // name, max age, match gs rest times 
                {{28000, "28"}, {32000, "32"}, {36000, "36"}, {40000, "40"}, 
                 {44000, "44"}, {48000, "48"}, {52000, "52"}, {0, NULL}}
            }, {
                "ET", 10, 120, 60, 180, // name, max age, match gs rest times 
                {{25000, "25"}, {28000, "28"}, {32000, "32"}, {36000, "36"}, 
                 {40000, "40"}, {44000, "44"}, {48000, "48"}, {52000, "52"}, {0, NULL}}
            }, { NULL, 0, 0, 0, 0, {{0, NULL}}}
        }
    }, { // swedish
        { // men
            {
                "Herrar", 1000, 300, 180, 600, // name, max age, match gs rest times 
                {{60000, "60"}, {66000, "66"}, {73000, "73"}, 
                 {81000, "81"}, {90000, "90"}, {100000, "100"}, {0, NULL}}
            }, {
                "Pojkar U20", 19, 240, 180, 600, // name, max age, match gs rest times 
                {{55000, "55"}, {60000, "60"}, {66000, "66"}, {73000, "73"}, 
                 {81000, "81"}, {90000, "90"}, {0, NULL}}
            }, {
                "Pojkar U17", 16, 180, 120, 600, // name, max age, match gs rest times 
                {{45000, "45"}, {50000, "50"}, {55000, "55"}, {60000, "60"}, 
                 {66000, "66"}, {73000, "73"}, {81000, "81"}, {0, NULL}}
            }, {
                "Pojkar U15", 14, 180, 120, 180, // name, max age, match gs rest times 
                {{34000, "34"}, {38000, "38"}, {42000, "42"}, {46000, "46"}, 
                 {50000, "50"}, {55000, "55"}, {60000, "60"}, {66000, "66"}, {0, NULL}}
            }, {
                "Pojkar U13", 12, 120, 60, 180, // name, max age, match gs rest times 
                {{30000, "30"}, {34000, "34"}, {38000, "38"}, {42000, "42"}, 
                 {46000, "46"}, {50000, "50"}, {55000, "55"}, {0, NULL}}
            }, {
                "Pojkar U11", 10, 120, 60, 180, // name, max age, match gs rest times 
                {{27000, "27"}, {30000, "30"}, {34000, "34"}, {38000, "38"}, {42000, "42"}, 
                 {46000, "46"}, {50000, "50"}, {55000, "55"}, {0, NULL}}
            }, { NULL, 0, 0, 0, 0, {{0, NULL}}}
        }, { // women
            {
                "Damer", 1000, 300, 180, 600, // name, max age, match gs rest times 
                {{48000, "48"}, {52000, "52"}, {57000, "57"}, 
                 {63000, "63"}, {70000, "70"}, {78000, "78"}, {0, NULL}}
            }, {
                "Flickor U20", 19, 240, 180, 600, // name, max age, match gs rest times 
                {{48000, "48"}, {52000, "52"}, {57000, "57"}, 
                 {63000, "63"}, {70000, "70"}, {0, NULL}}
            }, {
                "Flickor U17", 16, 180, 120, 600, // name, max age, match gs rest times 
                {{44000, "44"}, {48000, "48"}, {52000, "52"}, {57000, "57"}, 
                 {63000, "63"}, {0, NULL}}
            }, {
                "Flickor U15", 14, 180, 120, 180, // name, max age, match gs rest times 
                {{32000, "32"}, {36000, "36"}, {40000, "40"}, {44000, "44"}, 
                 {48000, "48"}, {52000, "52"}, {57000, "57"}, {63000, "63"}, {0, NULL}}
            }, {
                "Flickor U13", 12, 120, 60, 180, // name, max age, match gs rest times 
                {{28000, "28"}, {32000, "32"}, {36000, "36"}, {40000, "40"}, 
                 {44000, "44"}, {48000, "48"}, {52000, "52"}, {0, NULL}}
            }, {
                "Flickor U11", 10, 120, 60, 180, // name, max age, match gs rest times 
                {{25000, "25"}, {28000, "28"}, {32000, "32"}, {36000, "36"}, 
                 {40000, "40"}, {44000, "44"}, {48000, "48"}, {52000, "52"}, {0, NULL}}
            }, { NULL, 0, 0, 0, 0, {{0, NULL}}}
        }
    }, { // estonian
        { // men
            {
                "M", 1000, 300, 180, 600, // name, max age, match gs rest times 
                {{60000, "60"}, {66000, "66"}, {73000, "73"}, 
                 {81000, "81"}, {90000, "90"}, {100000, "100"}, {0, NULL}}
            }, {
                "M", 19, 240, 180, 600, // name, max age, match gs rest times 
                {{55000, "55"}, {60000, "60"}, {66000, "66"}, {73000, "73"}, 
                 {81000, "81"}, {90000, "90"}, {100000, "100"}, {0, NULL}}
            }, {
                "AP", 16, 180, 60, 600, // name, max age, match gs rest times 
                {{50000, "50"}, {55000, "55"}, {60000, "60"}, 
                 {66000, "66"}, {73000, "73"}, {81000, "81"}, {90000, "90"}, {0, NULL}}
            }, {
                "BP", 14, 180, 60, 180, // name, max age, match gs rest times 
                {{34000, "34"}, {38000, "38"}, {42000, "42"}, {45000, "45"}, 
                 {50000, "50"}, {55000, "55"}, {60000, "60"}, {66000, "66"}, 
                 {73000, "73"}, {0, NULL}}
            }, {
                "CP", 12, 120, 60, 180, // name, max age, match gs rest times 
                {{27000, "27"}, {30000, "30"}, {34000, "34"}, {38000, "38"}, {42000, "42"}, 
                 {46000, "46"}, {50000, "50"}, {55000, "55"}, {60000, "60"}, {0, NULL}}
            }, {
                "DP", 10, 120, 60, 180, // name, max age, match gs rest times 
                {{27000, "27"}, {30000, "30"}, {34000, "34"}, {38000, "38"}, {42000, "42"}, 
                 {46000, "46"}, {50000, "50"}, {55000, "55"}, {0, NULL}}
            }, { NULL, 0, 0, 0, 0, {{0, NULL}}}
        }, { // women
            {
                "N", 1000, 300, 180, 600, // name, max age, match gs rest times 
                {{48000, "48"}, {52000, "52"}, {57000, "57"}, 
                 {63000, "63"}, {70000, "70"}, {78000, "78"}, {0, NULL}}
            }, {
                "N", 19, 240, 180, 600, // name, max age, match gs rest times 
                {{44000, "44"}, {48000, "48"}, {52000, "52"}, {57000, "57"}, 
                 {63000, "63"}, {70000, "70"}, {78000, "78"}, {0, NULL}}
            }, {
                "AT", 16, 180, 60, 600, // name, max age, match gs rest times 
                {{40000, "40"}, {44000, "44"}, {48000, "48"}, {52000, "52"}, 
                 {57000, "57"}, {63000, "63"}, {70000, "70"}, {0, NULL}}
            }, {
                "BT", 14, 180, 60, 180, // name, max age, match gs rest times 
                {{36000, "36"}, {40000, "40"}, {44000, "44"}, 
                 {48000, "48"}, {52000, "52"}, {57000, "57"}, {0, NULL}}
            }, {
                "CT", 12, 120, 60, 180, // name, max age, match gs rest times 
                {{28000, "28"}, {32000, "32"}, {36000, "36"}, {40000, "40"}, 
                 {44000, "44"}, {48000, "48"}, {0, NULL}}
            }, {
                "DT", 10, 120, 60, 180, // name, max age, match gs rest times 
                {{25000, "25"}, {28000, "28"}, {32000, "32"}, {36000, "36"}, 
                 {40000, "40"}, {44000, "44"}, {48000, "48"}, {52000, "52"}, {0, NULL}}
            }, { NULL, 0, 0, 0, 0, {{0, NULL}}}
        }
    }
};

struct cat_def category_definitions[NUM_CATEGORIES];
gint num_categories = 0;

gint find_age_index(const gchar *category)
{
    gint i;

    for (i = 0; i < num_categories; i++) {
        if (category == NULL || category_definitions[i].agetext[0] == 0)
            continue;
        if (strncmp(category_definitions[i].agetext, 
                    category,
                    strlen(category_definitions[i].agetext)) == 0)
            return i;
    }
    //g_print("could not find%s\n", category);
    return -1;
}

static gint find_age_index_by_age(gint age, gint gender)
{
    gint i, age_ix = -1, best_age = 100000000;

    for (i = 0; i < num_categories; i++) {
        if (age <= category_definitions[i].age && 
            best_age > category_definitions[i].age &&
            gender == category_definitions[i].gender) {
            age_ix = i;
            best_age = category_definitions[i].age;
        }
    }

    return age_ix;
}

static gint find_weight_index(gint ageix, const gchar *category)
{
    gint i;

    for (i = 0; i < NUM_CAT_DEF_WEIGHTS && category_definitions[ageix].weights[i].weight; i++) {
        if (category == NULL || category_definitions[ageix].weights[i].weighttext[0] == 0)
            continue;
        if (strstr(category, category_definitions[ageix].weights[i].weighttext))
            return i;
    }

    return -1;
}

static gint find_weight_index_by_weight(gint ageix, gint weight)
{
    gint i, w_ix = -1, best_weight = 100000000;

    for (i = 0; i < NUM_CAT_DEF_WEIGHTS && category_definitions[ageix].weights[i].weight; i++) {
        if (weight <= category_definitions[ageix].weights[i].weight &&
            best_weight > category_definitions[ageix].weights[i].weight) {
            w_ix = i;
            best_weight = category_definitions[ageix].weights[i].weight;
        }
    }

    return w_ix;
}

gboolean fill_in_next_match_message_data(const gchar *cat, struct msg_next_match *msg)
{
    gint i = find_age_index(cat);
    if (i < 0)
        return FALSE;

    msg->match_time = category_definitions[i].match_time;
    msg->gs_time = category_definitions[i].gs_time;
    msg->rest_time = category_definitions[i].rest_time;
    msg->pin_time_ippon = category_definitions[i].pin_time_ippon;
    msg->pin_time_wazaari = category_definitions[i].pin_time_wazaari;
    msg->pin_time_yuko = category_definitions[i].pin_time_yuko;
    msg->pin_time_koka = category_definitions[i].pin_time_koka;

    return TRUE;
}

gint get_category_rest_time(const gchar *cat)
{
    gint i = find_age_index(cat);
    if (i < 0)
        return 0;
    return category_definitions[i].rest_time;
}

gchar *find_correct_category(gint age, gint weight, gint gender, const gchar *category_now, gboolean best_match)
{
    gint i, age_ix = 0, w_ix, weight1 = 0;

    if ((age == 0 || gender == 0) && category_now) {
        i = find_age_index(category_now);
        if (i >= 0) {
            if (age == 0)
                age = category_definitions[i].age;
            if (gender == 0)
                gender = category_definitions[i].gender;
        }
    }

    if (age == 0 || gender == 0)
        return NULL;
	
    age_ix = find_age_index_by_age(age, gender);
    if (age_ix < 0)
        return NULL;

    /* What is the weight category indicates? */
    if (category_now) {
        w_ix = find_weight_index(age_ix, category_now);
        if (w_ix >= 0)
            weight1 = category_definitions[age_ix].weights[w_ix].weight;
    }

    /* If we have no real weight or we want to keep the reg. category use weight1 */
    if (weight == 0 || (weight1 > weight && best_match == FALSE)) {
        weight = weight1;
    }

    if (weight == 0)
        return g_strdup_printf("%s", category_definitions[age_ix].agetext);

    w_ix = find_weight_index_by_weight(age_ix, weight);
    if (w_ix < 0)
        return NULL;

    return g_strdup_printf("%s%s", 
                           category_definitions[age_ix].agetext,
                           category_definitions[age_ix].weights[w_ix].weighttext);
}

gint compare_categories(gchar *cat1, gchar *cat2)
{
    gint a1, a2, w1, w2;

    if (cat1 == NULL)
        return -1;
    if (cat2 == NULL)
        return 1;

    /* age is the most significant */
    a1 = find_age_index(cat1);
    a2 = find_age_index(cat2);
    if (a1 < 0 && a2 >= 0)
        return -1;
    if (a2 < 0 && a1 >= 0)
        return 1;
    if (a1 < 0 || a2 < 0)
        goto out;

    if (category_definitions[a1].age > category_definitions[a2].age)
        return 1;
    if (category_definitions[a1].age < category_definitions[a2].age)
        return -1;

    /* gender is the next significant criteria */
    if ((category_definitions[a1].gender & IS_MALE) && 
        (category_definitions[a2].gender & IS_FEMALE))
        return 1;
    if ((category_definitions[a1].gender & IS_FEMALE) && 
        (category_definitions[a2].gender & IS_MALE))
        return -1;

    /* weight is the least significant criteria */
    w1 = find_weight_index(a1, cat1);
    w2 = find_weight_index(a2, cat2);
    if (w1 < 0 && w2 >= 0)
        return -1;
    if (w2 < 0 && w1 >= 0)
        return 1;
    if (w1 < 0 || w2 < 0)
        goto out;

    if (category_definitions[a1].weights[w1].weight > category_definitions[a2].weights[w2].weight)
        return 1;
    if (category_definitions[a1].weights[w1].weight < category_definitions[a2].weights[w2].weight)
        return -1;

out:
    return strcmp(cat1, cat2);
}

extern void db_insert_cat_def_table_data_begin(void);
extern void db_insert_cat_def_table_data_end(void);

static void init_cat_data(void)
{
    gint i, j, k, n;
    struct cat_def def;

    i = draw_system;
    if (i >= NUM_DRAWS)
        i = 0;

    db_insert_cat_def_table_data_begin();
    
    for (j = 0; j < 2; j++) {
        for (k = 0; official_categories[i][j][k].name; k++) {
            def.age = official_categories[i][j][k].maxage;
            strcpy(def.agetext, official_categories[i][j][k].name);
            def.match_time = official_categories[i][j][k].match_time;
            def.rest_time = official_categories[i][j][k].rest_time;
            def.gs_time = official_categories[i][j][k].gs_time;
            if (i == DRAW_FINNISH && def.age <= 10) { // E-juniors
                def.pin_time_koka = 0;
                def.pin_time_yuko = 5;
                def.pin_time_wazaari = 10;
                def.pin_time_ippon = 15;
            } else {
                def.pin_time_koka = 10;
                def.pin_time_yuko = 15;
                def.pin_time_wazaari = 20;
                def.pin_time_ippon = 25;
            }

            def.gender = (j == 0) ? IS_MALE : IS_FEMALE;

            for (n = 0; official_categories[i][j][k].weights[n].weight; n++) {
                def.weights[0].weight = official_categories[i][j][k].weights[n].weight;
                sprintf(def.weights[0].weighttext, "-%d", def.weights[0].weight/1000);
                db_insert_cat_def_table_data(&def);
            }

            sprintf(def.weights[0].weighttext, "+%d", def.weights[0].weight/1000);
            def.weights[0].weight = 1000000;
            db_insert_cat_def_table_data(&def);
        } // k
    } // j

    db_insert_cat_def_table_data_end();
}

void read_cat_definitions(void)
{
    gint row;
    gint numrows;

    if (catdef_needs_init())
        init_cat_data();

    memset(&category_definitions, 0, sizeof(category_definitions));
    num_categories = 0;

    numrows = db_get_table("select * from catdef order by \"age\", \"weight\", \"flags\" asc");
    if (numrows < 0) {
        g_print("FATAL ERROR: CANNOT OPEN CAT DEF TABLE!\n");
        goto out;
    }

    for (row = 0; row < numrows; row++) {
        gchar *agetext = db_get_data(row, "agetext");
        gchar *agestr = db_get_data(row, "age");
        gchar *weighttext = db_get_data(row, "weighttext");
        gchar *weightstr = db_get_data(row, "weight");
        gchar *flagsstr = db_get_data(row, "flags");
        gchar *matchtimestr = db_get_data(row, "matchtime");
        gchar *resttimestr = db_get_data(row, "resttime");
        gchar *gstimestr = db_get_data(row, "gstime");
        gchar *pintimekokastr = db_get_data(row, "pintimekoka");
        gchar *pintimeyukostr = db_get_data(row, "pintimeyuko");
        gchar *pintimewazaaristr = db_get_data(row, "pintimewazaari");
        gchar *pintimeipponstr = db_get_data(row, "pintimeippon");
        gint age = atoi(agestr);
        gint weight = atoi(weightstr);
        gint flags = atoi(flagsstr);
        gint matchtime = atoi(matchtimestr);
        gint resttime = atoi(resttimestr);
        gint gstime = atoi(gstimestr);
        gint pintimekoka = atoi(pintimekokastr);
        gint pintimeyuko = atoi(pintimeyukostr);
        gint pintimewazaari = atoi(pintimewazaaristr);
        gint pintimeippon = atoi(pintimeipponstr);

        //g_print("CAT DEF LINE: %s %d %s %d %d\n",
        //	agetext, age, weighttext, weight, flags);

        /* find existing category line */
        gint i;
        for (i = 0; i < num_categories; i++) {
            if (category_definitions[i].age    == age &&
                category_definitions[i].gender == flags)
                break;
        }
        /* new category */
        if (i >= num_categories)
            num_categories = i + 1;

        category_definitions[i].age = age;
        category_definitions[i].gender = flags;
        strcpy(category_definitions[i].agetext, agetext);
        category_definitions[i].match_time = matchtime;
        category_definitions[i].rest_time = resttime;
        category_definitions[i].gs_time = gstime;
        category_definitions[i].pin_time_koka = pintimekoka;
        category_definitions[i].pin_time_yuko = pintimeyuko;
        category_definitions[i].pin_time_wazaari = pintimewazaari;
        category_definitions[i].pin_time_ippon = pintimeippon;

        gint j;
        for (j = 0; category_definitions[i].weights[j].weight && j < NUM_CAT_DEF_WEIGHTS; j++)
            ;
        if (j < NUM_CAT_DEF_WEIGHTS) {
            category_definitions[i].weights[j].weight = weight;
            strcpy(category_definitions[i].weights[j].weighttext, weighttext);
        }
    }
	
out:
    db_close_table();
}

#define Q_RESET 1000

void set_categories_dialog(GtkWidget *w, gpointer arg) 
{
    GtkWidget *dialog, *tmp, *scrolled_window, *vbox, *tables[NUM_CATEGORIES];
    struct {
        GtkWidget *age, *agetext, *matchtime, *resttime, *gstime, *pink, *piny, *pinw, *pini;
        gint gender;
        struct {
            GtkWidget *weight, *weighttext;
        } weights[NUM_CAT_DEF_WEIGHTS];
    } fields[NUM_CATEGORIES];
    gint i, j, m = 0, f = NUM_CATEGORIES/2;

    dialog = gtk_dialog_new_with_buttons ("Sarjat",
                                          NULL,
                                          GTK_DIALOG_MODAL,
                                          _("Reset to Defaults"), Q_RESET,
                                          GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL,
                                          GTK_STOCK_OK, GTK_RESPONSE_OK,
                                          NULL);

    scrolled_window = gtk_scrolled_window_new(NULL, NULL);
    gtk_widget_set_size_request(scrolled_window, FRAME_WIDTH, FRAME_HEIGHT);
    gtk_container_set_border_width(GTK_CONTAINER(scrolled_window), 4);
    gtk_container_add(GTK_CONTAINER(GTK_DIALOG(dialog)->vbox), scrolled_window);

    vbox = gtk_vbox_new(FALSE, 1);
    gtk_container_set_border_width(GTK_CONTAINER(vbox), 1);

    for (i = 0; i < NUM_CATEGORIES; i++)
        tables[i] = gtk_table_new(NUM_CAT_DEF_WEIGHTS + 9, 3, FALSE);

    gtk_box_pack_start(GTK_BOX(vbox), gtk_label_new(_("----- Men -----")), FALSE, TRUE, 0);
    for (i = 0; i < NUM_CATEGORIES/2; i++) {
        gtk_box_pack_start(GTK_BOX(vbox), tables[i], FALSE, TRUE, 0);
        gtk_box_pack_start(GTK_BOX(vbox), gtk_label_new(" "), FALSE, TRUE, 0);
    }

    gtk_box_pack_start(GTK_BOX(vbox), gtk_label_new(_("----- Women -----")), FALSE, TRUE, 0);
    for (i = NUM_CATEGORIES/2; i < NUM_CATEGORIES; i++) {
        gtk_box_pack_start(GTK_BOX(vbox), tables[i], FALSE, TRUE, 0);
        gtk_box_pack_start(GTK_BOX(vbox), gtk_label_new(" "), FALSE, TRUE, 0);
    }

    gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(scrolled_window), vbox);

    for (i = 0; i < NUM_CATEGORIES; i++) {
        gtk_table_attach_defaults(GTK_TABLE(tables[i]), gtk_label_new(_("Highest age:")),      0, 1, 0, 1);
        gtk_table_attach_defaults(GTK_TABLE(tables[i]), gtk_label_new(_("Age text:")),         0, 1, 1, 2);
        gtk_table_attach_defaults(GTK_TABLE(tables[i]), gtk_label_new(_("Match time:")),       2, 3, 0, 1);
        gtk_table_attach_defaults(GTK_TABLE(tables[i]), gtk_label_new(_("Rest time:")),        2, 3, 2, 3);
        gtk_table_attach_defaults(GTK_TABLE(tables[i]), gtk_label_new(_("Golden Score:")),     2, 3, 1, 2);
        gtk_table_attach_defaults(GTK_TABLE(tables[i]), gtk_label_new(_("Pin times (IWYK):")), 4, 8, 0, 1);

        /* age */
        tmp = fields[i].age = gtk_entry_new();
        gtk_entry_set_max_length(GTK_ENTRY(tmp), 4);
        gtk_entry_set_width_chars(GTK_ENTRY(tmp), 10);
        gtk_table_attach_defaults(GTK_TABLE(tables[i]), tmp, 1, 2, 0, 1);

        /* age text */
        tmp = fields[i].agetext = gtk_entry_new();
        gtk_entry_set_max_length(GTK_ENTRY(tmp), 16);
        gtk_entry_set_width_chars(GTK_ENTRY(tmp), 10);
        gtk_table_attach_defaults(GTK_TABLE(tables[i]), tmp, 1, 2, 1, 2);

        /* match time */
        tmp = fields[i].matchtime = gtk_entry_new();
        gtk_entry_set_max_length(GTK_ENTRY(tmp), 3);
        gtk_entry_set_width_chars(GTK_ENTRY(tmp), 3);
        gtk_table_attach_defaults(GTK_TABLE(tables[i]), tmp, 3, 4, 0, 1);

        /* rest time */
        tmp = fields[i].resttime = gtk_entry_new();
        gtk_entry_set_max_length(GTK_ENTRY(tmp), 3);
        gtk_entry_set_width_chars(GTK_ENTRY(tmp), 3);
        gtk_table_attach_defaults(GTK_TABLE(tables[i]), tmp, 3, 4, 2, 3);

        /* golden score time */
        tmp = fields[i].gstime = gtk_entry_new();
        gtk_entry_set_max_length(GTK_ENTRY(tmp), 3);
        gtk_entry_set_width_chars(GTK_ENTRY(tmp), 3);
        gtk_table_attach_defaults(GTK_TABLE(tables[i]), tmp, 3, 4, 1, 2);

        /* pin time ippon */
        tmp = fields[i].pini = gtk_entry_new();
        gtk_entry_set_max_length(GTK_ENTRY(tmp), 2);
        gtk_entry_set_width_chars(GTK_ENTRY(tmp), 2);
        gtk_table_attach_defaults(GTK_TABLE(tables[i]), tmp, 4, 5, 1, 2);

        /* pin time waza-ari */
        tmp = fields[i].pinw = gtk_entry_new();
        gtk_entry_set_max_length(GTK_ENTRY(tmp), 2);
        gtk_entry_set_width_chars(GTK_ENTRY(tmp), 2);
        gtk_table_attach_defaults(GTK_TABLE(tables[i]), tmp, 5, 6, 1, 2);

        /* pin time yuko */
        tmp = fields[i].piny = gtk_entry_new();
        gtk_entry_set_max_length(GTK_ENTRY(tmp), 2);
        gtk_entry_set_width_chars(GTK_ENTRY(tmp), 2);
        gtk_table_attach_defaults(GTK_TABLE(tables[i]), tmp, 6, 7, 1, 2);

        /* pin time koka */
        tmp = fields[i].pink = gtk_entry_new();
        gtk_entry_set_max_length(GTK_ENTRY(tmp), 2);
        gtk_entry_set_width_chars(GTK_ENTRY(tmp), 2);
        gtk_table_attach_defaults(GTK_TABLE(tables[i]), tmp, 7, 8, 1, 2);

        /* weights */
        gtk_table_attach_defaults(GTK_TABLE(tables[i]), gtk_label_new(_("Highest weight (g):")), 8, 9, 0, 1);
        gtk_table_attach_defaults(GTK_TABLE(tables[i]), gtk_label_new(_("Weight text:")),    8, 9, 1, 2);

        for (j = 0; j < NUM_CAT_DEF_WEIGHTS; j++) {
            tmp = fields[i].weights[j].weight = gtk_entry_new();
            gtk_entry_set_max_length(GTK_ENTRY(tmp), 12);
            gtk_entry_set_width_chars(GTK_ENTRY(tmp), 6);
            gtk_table_attach_defaults(GTK_TABLE(tables[i]), tmp, j+9, j+10, 0, 1);

            tmp = fields[i].weights[j].weighttext = gtk_entry_new();
            gtk_entry_set_max_length(GTK_ENTRY(tmp), 12);
            gtk_entry_set_width_chars(GTK_ENTRY(tmp), 6);
            gtk_table_attach_defaults(GTK_TABLE(tables[i]), tmp, j+9, j+10, 1, 2);
        }
    }

    for (i = 0; i < NUM_CATEGORIES; i++) {
        gchar buf[32], mt[8], rt[8], gt[8], it[8], wt[8], yt[8], kt[8];

        for (j = 0; j < NUM_CAT_DEF_WEIGHTS; j++) {
            if (category_definitions[i].weights[j].weight == 0)
                continue;

            sprintf(buf, "%d", category_definitions[i].weights[j].weight);
            if (category_definitions[i].gender & IS_MALE) {
                gtk_entry_set_text(GTK_ENTRY(fields[m].weights[j].weight), buf);
                gtk_entry_set_text(GTK_ENTRY(fields[m].weights[j].weighttext),
                                   category_definitions[i].weights[j].weighttext);
            } else if (category_definitions[i].gender & IS_FEMALE) {
                gtk_entry_set_text(GTK_ENTRY(fields[f].weights[j].weight), buf);
                gtk_entry_set_text(GTK_ENTRY(fields[f].weights[j].weighttext),
                                   category_definitions[i].weights[j].weighttext);
            }
        }

        sprintf(buf, "%d", category_definitions[i].age);
        sprintf(mt, "%d", category_definitions[i].match_time);
        sprintf(rt, "%d", category_definitions[i].rest_time);
        sprintf(gt, "%d", category_definitions[i].gs_time);
        sprintf(it, "%d", category_definitions[i].pin_time_ippon);
        sprintf(wt, "%d", category_definitions[i].pin_time_wazaari);
        sprintf(yt, "%d", category_definitions[i].pin_time_yuko);
        sprintf(kt, "%d", category_definitions[i].pin_time_koka);

        if (category_definitions[i].gender & IS_MALE) {
            gtk_entry_set_text(GTK_ENTRY(fields[m].age), buf);
            gtk_entry_set_text(GTK_ENTRY(fields[m].agetext), category_definitions[i].agetext);
            gtk_entry_set_text(GTK_ENTRY(fields[m].matchtime), mt);
            gtk_entry_set_text(GTK_ENTRY(fields[m].resttime), rt);
            gtk_entry_set_text(GTK_ENTRY(fields[m].gstime), gt);
            gtk_entry_set_text(GTK_ENTRY(fields[m].pini), it);
            gtk_entry_set_text(GTK_ENTRY(fields[m].pinw), wt);
            gtk_entry_set_text(GTK_ENTRY(fields[m].piny), yt);
            gtk_entry_set_text(GTK_ENTRY(fields[m].pink), kt);
			
            if (m < NUM_CATEGORIES/2-1) 
                m++;
        } else if (category_definitions[i].gender & IS_FEMALE) {
            gtk_entry_set_text(GTK_ENTRY(fields[f].age), buf);
            gtk_entry_set_text(GTK_ENTRY(fields[f].agetext), category_definitions[i].agetext);
            gtk_entry_set_text(GTK_ENTRY(fields[f].matchtime), mt);
            gtk_entry_set_text(GTK_ENTRY(fields[f].resttime), rt);
            gtk_entry_set_text(GTK_ENTRY(fields[f].gstime), gt);
            gtk_entry_set_text(GTK_ENTRY(fields[f].pini), it);
            gtk_entry_set_text(GTK_ENTRY(fields[f].pinw), wt);
            gtk_entry_set_text(GTK_ENTRY(fields[f].piny), yt);
            gtk_entry_set_text(GTK_ENTRY(fields[f].pink), kt);

            if (f < NUM_CATEGORIES-1) 
                f++;
        }
    }

    gtk_widget_show_all(dialog);

    gint response = gtk_dialog_run(GTK_DIALOG(dialog));

    if (response == GTK_RESPONSE_OK) {
        struct cat_def def;

        db_delete_cat_def_table_data();
	db_insert_cat_def_table_data_begin();

        for (i = 0; i < NUM_CATEGORIES; i++) {
            def.age = atoi(gtk_entry_get_text(GTK_ENTRY(fields[i].age)));
            strcpy(def.agetext, gtk_entry_get_text(GTK_ENTRY(fields[i].agetext)));
            def.match_time = atoi(gtk_entry_get_text(GTK_ENTRY(fields[i].matchtime)));
            def.rest_time = atoi(gtk_entry_get_text(GTK_ENTRY(fields[i].resttime)));
            def.gs_time = atoi(gtk_entry_get_text(GTK_ENTRY(fields[i].gstime)));
            def.pin_time_ippon = atoi(gtk_entry_get_text(GTK_ENTRY(fields[i].pini)));
            def.pin_time_wazaari = atoi(gtk_entry_get_text(GTK_ENTRY(fields[i].pinw)));
            def.pin_time_yuko = atoi(gtk_entry_get_text(GTK_ENTRY(fields[i].piny)));
            def.pin_time_koka = atoi(gtk_entry_get_text(GTK_ENTRY(fields[i].pink)));
			
            if (i < NUM_CATEGORIES/2)
                def.gender = IS_MALE;
            else
                def.gender = IS_FEMALE;

            for (j = 0; j < NUM_CAT_DEF_WEIGHTS; j++) {
                def.weights[0].weight = 
                    atoi(gtk_entry_get_text(GTK_ENTRY(fields[i].weights[j].weight)));
                strcpy(def.weights[0].weighttext, 
                       gtk_entry_get_text(GTK_ENTRY(fields[i].weights[j].weighttext)));
                if (def.age && def.weights[0].weight)
                    db_insert_cat_def_table_data(&def);
            }
        }

	db_insert_cat_def_table_data_end();
        read_cat_definitions();

        db_cat_def_table_done();
    } else if (response == Q_RESET) {
        db_delete_cat_def_table_data();
        init_cat_data();
        read_cat_definitions();
        db_cat_def_table_done();
    }

    gtk_widget_destroy(dialog);
}

