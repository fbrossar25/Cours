import { NgModule } from '@angular/core';
import { CommonModule } from '@angular/common';
import { HeaderComponent } from '../components/header/header.component';
import { FooterComponent } from '../components/footer/footer.component';
import { NavComponent } from '../components/nav/nav.component';
import { UserInterfaceComponent } from './user-interface/user-interface.component';
import { AppRoutingModule } from 'src/app/app-routing.module';
import { LoginModule } from 'src/app/login/containers/login.module';

@NgModule({
  declarations: [NavComponent, HeaderComponent, FooterComponent, UserInterfaceComponent],
  imports: [
    CommonModule,
    AppRoutingModule,
    LoginModule
  ],
  exports: [UserInterfaceComponent]
})
export class UserInterfaceModule { }
