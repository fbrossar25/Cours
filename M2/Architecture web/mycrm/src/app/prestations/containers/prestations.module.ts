import { PrestationComponent } from './../components/prestation/prestation.component';
import { NgModule } from '@angular/core';
import { CommonModule } from '@angular/common';
import { PrestationsRoutingModule } from './prestations-routing.module';
import { ListePrestationsComponent } from './liste-prestations/liste-prestations.component';
import { SharedModule } from 'src/app/shared/shared.module';
import { FormsModule, ReactiveFormsModule } from '@angular/forms';
import { AddPrestationComponent } from './add-prestation/add-prestation.component';

@NgModule({
  declarations: [ListePrestationsComponent, PrestationComponent, AddPrestationComponent],
  imports: [
    CommonModule,
    PrestationsRoutingModule,
    SharedModule,
    FormsModule,
    ReactiveFormsModule
  ],
  providers: []
})
export class PrestationsModule { }
