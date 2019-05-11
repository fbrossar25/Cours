import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { ListePrestationsComponent } from './liste-prestations.component';

describe('ListePrestationsComponent', () => {
  let component: ListePrestationsComponent;
  let fixture: ComponentFixture<ListePrestationsComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ ListePrestationsComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(ListePrestationsComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
