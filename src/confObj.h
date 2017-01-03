/*
 *  confObj.h
 *  uvff
 *
 *  Created by Adrian Partl on 4/15/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef CONFOBJ_H
#define CONFOBJ_H

/*--- Includes ----------------------------------------------------------*/
#include "parse_ini.h"
#include <stdint.h>
#include <stdbool.h>


/*--- ADT handle --------------------------------------------------------*/
typedef struct confObj_struct *confObj_t;


/*--- Implemention of main structure ------------------------------------*/
struct confObj_struct {
    //General
    int            input_doubleprecision;
    int            num_snapshots;
    char           *redshift_file;
    char           *igm_density_file;
    char           *igm_clump_file;
    
    int            grid_size;
    double         box_size;
    double         lin_scales;
    double         inc_log_scales;
    
    char           *sources_file;
    char           *nion_file;
    double         evol_time;
    double         redshift;
    
    int            dens_in_overdensity;
    double         mean_density;
    int            default_mean_density;
    
    int            inputfiles_comoving;
    
    double         h;
    double         omega_b;
    double         omega_m;
    double         omega_l;
    double         sigma8;
    double         Y;
    
    char           *out_XHII_file;
    
    int            use_web_model;
    char           *photHI_bg_file;
    int            const_photHI;
    double         photHI_bg;
    int            calc_mfp;
    double         mfp;
    int            write_photHI_file;
    char           *out_photHI_file;
    
    int            calc_recomb;
    char           *recomb_table;
    double         zmin, zmax, dz;
    double         fmin, fmax, df;
    double         dcellmin, dcellmax, ddcell;
    
    int            calc_ion_history;
    
    int            read_nrec_file;
    double         redshift_prev_snap;
    char           *nrec_file;
    char           *output_nrec_file;
};


/*--- Prototypes of exported functions ----------------------------------*/
extern confObj_t
readConfObj(char *fileName);

extern confObj_t
confObj_new(parse_ini_t ini);

extern void
confObj_del(confObj_t *config);


#endif
