/*
** Copyright (C) 2016 Airbus Group, stephane duverger <stephane.duverger@airbus.com>
**
** This program is free software; you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation; either version 2 of the License, or
** (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License along
** with this program; if not, write to the Free Software Foundation, Inc.,
** 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/
#include <vmm.h>
#include <debug.h>
#include <info_data.h>

extern info_data_t *info;

static void vmm_ctrl_init()
{
   info->vmm.ctrl.active_cr3 = &__cr3;
}

void vmm_init()
{
   vmm_ctrl_init();
   vmm_vmc_init();
}

void __regparm__(1) vmm_start()
{
   vmm_vmc_start();
}
