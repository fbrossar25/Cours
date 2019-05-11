import { BrowserModule } from '@angular/platform-browser';
import { NgModule } from '@angular/core';

import { AppComponent } from './app.component';
import { HeaderComponent } from './header/header.component';
import { RechercheComponent } from './recherche/recherche.component';
import { FormsModule} from '@angular/forms';
import { CryptoComponent } from './crypto/crypto.component';
import { HttpClientModule } from '@angular/common/http';
import {RouterModule, Routes} from '@angular/router';
import { DetailComponent } from './detail/detail.component';


const appRoutes: Routes = [
  {path: 'recherche', component: RechercheComponent },
  { path: 'detail/:id', component: DetailComponent}
];

@NgModule({
  declarations: [
    AppComponent,
    HeaderComponent,
    RechercheComponent,
    CryptoComponent,
    DetailComponent
  ],
  imports: [
    BrowserModule,
    FormsModule,
    HttpClientModule,
    RouterModule.forRoot (appRoutes)
  ],
  providers: [],
  bootstrap: [AppComponent]
})
export class AppModule { }
