import { AddPrestationComponent } from './add-prestation/add-prestation.component';
import { NgModule } from '@angular/core';
import { Routes, RouterModule } from '@angular/router';
import { ListePrestationsComponent } from './liste-prestations/liste-prestations.component';

const routes: Routes = [
  {path: '', redirectTo: 'list', pathMatch: 'full'},
  { path: 'list', component: ListePrestationsComponent, children: [
    {path: 'add', component: AddPrestationComponent}
  ]}
];

@NgModule({
  imports: [RouterModule.forChild(routes)],
  exports: [RouterModule]
})
export class PrestationsRoutingModule { }
