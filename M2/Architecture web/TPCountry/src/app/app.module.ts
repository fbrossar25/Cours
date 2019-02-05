import { BrowserModule } from '@angular/platform-browser';
import { NgModule } from '@angular/core';

import { AppRoutingModule } from './app-routing.module';
import { AppComponent } from './app.component';
import { HeaderComponent } from './header/header.component';
import { Routes, RouterModule } from '@angular/router';
import { HttpClientModule } from '@angular/common/http';
import { CountryComponent } from './country/country.component';
import { CountryListComponent } from './country-list/country-list.component';
import { SearchComponent } from './search/search.component';
import { NavComponent } from './nav/nav.component';

const appRoutes: Routes = [
  { path : '', redirectTo: 'country/France', pathMatch: 'full' },
  {path: 'country/:name', component: CountryComponent},
  {path: 'search/:param/:value', component: CountryComponent}
];

@NgModule({
  declarations: [
    AppComponent,
    HeaderComponent,
    CountryComponent,
    CountryListComponent,
    SearchComponent,
    NavComponent
  ],
  imports: [
    BrowserModule,
    AppRoutingModule,
    RouterModule.forRoot (appRoutes),
    HttpClientModule
  ],
  providers: [],
  bootstrap: [AppComponent]
})
export class AppModule { }
