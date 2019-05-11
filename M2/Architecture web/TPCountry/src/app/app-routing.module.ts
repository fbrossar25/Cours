import { NgModule } from '@angular/core';
import { Routes, RouterModule } from '@angular/router';
import { CountryComponent } from './country/country.component';
import { CountryListComponent } from './country-list/country-list.component';

const routes: Routes = [
  {path: '', redirectTo: 'country/FRA', pathMatch: 'full' },
  {path: 'country/:code', component: CountryComponent},
  {path: 'list/:property/:value', component: CountryListComponent}
];


@NgModule({
  imports: [RouterModule.forRoot(routes)],
  exports: [RouterModule]
})
export class AppRoutingModule { }
